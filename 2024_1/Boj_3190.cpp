#include <iostream>
#include <vector>

using namespace std;

int N;
int K;
int arr[100][100];
int L;
int timeCount=0;
int currentX;
int currentY;
char currentDir;
bool flag;

bool detectHit(int x, int y){
    //벽
    if(x<0 || x>N || y<0 || y>N){
        return false;
    }
    // 자기 몸
    else if(arr[x][y]==-1){
        return false;
    }
    
    return true;
}
void moveXY(int x , int y,int moveX,int moveY,int time){
    for(int i=0;i<time;i++){
        int newX=x+moveX;
        int newY = y+moveY;
        if(!detectHit(newX,newY)){
            flag=false;
            return;
        }else{
            timeCount+=1;
            // 사과가 있었을 때 
            if(arr[newX][newY]==1){
                //머리 부분 채우기
                arr[newX][newY]=-1;

            }//사과 없었을 때
            else if(arr[newX][newY]==0){
                arr[newX][newY]=-1;
                //꼬리 부분 지우기
                arr[x][y]=0;

            }
            x=newX;
            y=newY;
        }
    }
}
void changeDir(char currentDir,char changeDir,int x,int y,int time){
    if(currentDir=='S'){
       if(changeDir=='L'){
         moveXY(x,y,0,-1,time);
         currentDir='E';
       }else if(changeDir=='R'){
        moveXY(x,y,0,1,time);
        currentDir='W';
       }
    }else if(currentDir=='W'){
        if(changeDir=='L'){
         moveXY(x,y,-1,0,time);
         currentDir='N';
       }else if(changeDir=='R'){
        moveXY(x,y,1,0,time);
        currentDir='S';
       }

    }else if(currentDir=='N'){
         if(changeDir=='L'){
         moveXY(x,y,0,1,time);
         currentDir='W';
       }else if(changeDir=='R'){
        moveXY(x,y,0,-1,time);
        currentDir='E';
       }

    }else if(currentDir=='E'){
         if(changeDir=='L'){
         moveXY(x,y,1,0,time);
         currentDir='N';
       }else if(changeDir=='R'){
        moveXY(x,y,-1,0,time);
        currentDir='S';
       }

    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>N;
    cin>>K;
    // 사과는 1 자기 몸은 -1
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int x,y;
            cin>>x>>y;
            arr[x-1][y-1]=1;
        }
    }
    cin>>L;
    currentX=0;
    currentY=0;
    currentDir='S';
    flag=false;
   
    for(int i=0;i<L;i++){
        int time;
        cin.ignore();
        char dir;
        cin>>time>>dir;
        changeDir(currentDir,dir,currentX,currentY,time);
        if(flag){
            break;
        }

    }
    cout<<timeCount;
   

    return 0;
}