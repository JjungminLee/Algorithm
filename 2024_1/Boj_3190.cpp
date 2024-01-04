#include <iostream>
#include <vector>
#include<deque>
using namespace std;

int N;
int K;
int arr[100][100]={};
int L;
int timeCount=1;
char currentDir;
bool flag;
deque<pair<int,int>> dq;
vector<pair<int,char>> timeDir;
int moveX;
int moveY;

bool detectHit(int x, int y){
    //벽
    if(x<0 || x>=N || y<0 || y>=N){
        return false;
    }
    // 자기 몸
    else if(arr[x][y]==-1){
        return false;
    }
    
    return true;
}
void moveXY(int x , int y,int moveX,int moveY){
        int newX= x+moveX;
        int newY = y+moveY;
     
        if(!detectHit(newX,newY)){
            flag=true;
            return;
        }else{
            timeCount+=1;
            // 사과가 있었을 때 
            if(arr[newX][newY]==1){
                //머리 부분 채우기
                arr[newX][newY]=-1;
                dq.push_front({newX,newY});

            }//사과 없었을 때
            else if(arr[newX][newY]==0){
                arr[newX][newY]=-1;
                //꼬리 부분 지우기
                int tailX = dq.back().first;
                int tailY = dq.back().second;
                arr[tailX][tailY]=0;

                dq.push_front({newX,newY});
                dq.pop_back();

            }
           
        }
}
void changeDir(char& currentDir,char changeDir,int& moveX,int& moveY){
    if(currentDir=='S'){
        if(changeDir=='L'){
            currentDir='E';
            moveX=0;
            moveY=1;
       }else if(changeDir=='D'){
            currentDir='W';
            moveX=0;
            moveY=-1;
       }
      
    }else if(currentDir=='W'){
        if(changeDir=='L'){
            currentDir='S';
            moveX=1;
            moveY=0;
       }else if(changeDir=='D'){
            currentDir='N';
            moveX=-1;
            moveY=0;
       }
 
    }else if(currentDir=='N'){
        if(changeDir=='L'){
            currentDir='W';
            moveX=0;
            moveY=-1;
       }else if(changeDir=='D'){
            currentDir='E';
            moveX=0;
            moveY=1;
       }

    }else if(currentDir=='E'){
        if(changeDir=='L'){
            currentDir='N';
            moveX=-1;
            moveY=0;
        }else if(changeDir=='D'){
            currentDir='S';
            moveX=1;
            moveY=0;
       }
  
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>N;
    cin>>K;
    dq={};
    dq.push_back({0,0});
    // 사과는 1 자기 몸은 -1
   for(int i=0;i<K;i++){
    int x,y;
    cin>>x>>y;
    arr[x-1][y-1]=1;
   }
    cin>>L;
    currentDir='E';
    moveX = 0;
    moveY = 1;
    flag=false;
   
    for(int i=0;i<L;i++){
        int time;
        char dir;
        cin>>time>>dir;
        timeDir.push_back({time,dir});
    }

    while(true){
  
        if(flag){
            break;
        }
        
        int curX = dq.front().first;
        int curY = dq.front().second;

        moveXY(curX,curY,moveX,moveY);
        for(int i=0;i<timeDir.size();i++){
            if(timeDir[i].first==timeCount-1){
                changeDir(currentDir,timeDir[i].second,moveX,moveY);
            }
        }
       
        
        if(flag){
            break;
        }
        
        
    }
    cout<<timeCount<<endl;


    return 0;
}