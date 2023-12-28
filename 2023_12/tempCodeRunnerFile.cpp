#include<iostream>
#include <queue>
#include<math.h>
using namespace std;
int N;
int arr[101][101];
bool visits[101][101];
int minNum = 100;
int maxNum =1;
int ans=0;
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};

int BFS(){
    
    int cnt = 0;
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visits[i][j]){
                q.push({i,j});
                 while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    // 방문해도 되는 경우(재방문이 아닐때)
                    if(visits[x][y]){
                        visits[x][y]=false;
                        for(int i=0;i<4;i++){
                            int nX = x+dirX[i];
                            int nY = y+dirY[i];
                            if(nX>=0 && nX<N && nY>=0 && nY<N){
                                q.push({nX,nY});
                            }
                        }

                    }

                }
                cnt+=1;
                
            }
        }
    }
    
    return cnt;

}

void check(int height){
    // visit 초기화
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            visits[i][j]=true;
        }
    }
    // visit 하면 안되는 부분들 높이에 맞게 솎아내기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]<=height){
                visits[i][j]=false;
            }
        }
    }
    ans = max(BFS(),ans);

}
int main(){
    cin>>N;
    ans =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            if(minNum>arr[i][j]){
                minNum=arr[i][j];
            }
            if(maxNum<arr[i][j]){
                maxNum=arr[i][j];
            }
        }
    }
    for(int i=minNum;i<=maxNum;i++){
        
        check(i);
    }
    cout<<ans<<endl;
}