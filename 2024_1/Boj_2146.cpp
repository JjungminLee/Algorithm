#include <bits/stdc++.h>

using namespace std;

int N;
int arr[101][101];
int villageNum = 1;
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
int ans = INT_MAX;
bool visits[101][101];

// 다리 이름 붙이기
void bfs(int x,int y){
   
    queue<pair<int,int>> q;
    arr[x][y]=villageNum;
    q.push({x,y});

    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = curX+dirX[i];
            int ny = curY+dirY[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N){
                if(arr[nx][ny]==1){
                    q.push({nx,ny});
                    arr[nx][ny]=villageNum;
                }
            }
         }
    }

}

// 하나의 다리 라벨마다 다른 다리 라벨까지의 거리 계산
int checkBfs(int curIdx){
    int res = 0;

    queue<pair<int,int>> checkq;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visits[i][j]&&arr[i][j]==curIdx){
              
                checkq.push({i,j});
                visits[i][j]=true;
            }
        }
    }
    while(!checkq.empty()){
        // 해당 라벨에 있는 애들 개수
        int size = checkq.size();
        //여기까진 육지 bfs
        for(int i=0;i<size;i++){
            int x = checkq.front().first;
            int y = checkq.front().second;
            checkq.pop();
            for(int j=0;j<4;j++){
                int nx = x+dirX[j];
                int ny = y+dirY[j];
                if(nx>=0&&nx<N&&ny>=0&&ny<N){
                    if(arr[nx][ny]==0&&!visits[nx][ny]){
                        visits[nx][ny]=true;
                        checkq.push({nx,ny});

                    }
                    if(arr[nx][ny]!=0&&arr[nx][ny]!=curIdx){
                     
                        return res;
                    }
                }
            }
        }
        //바다 건너는것만 세주면됨
        res++;
    }

    return res;



}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==1){
                villageNum++;
                bfs(i,j);
            }
        }
    }
 
    for(int i=2;i<=villageNum;i++){
        ans=min(ans,checkBfs(i));
        memset(visits,false,sizeof(visits)); //초기화 해줘야!
    }
    cout<<ans<<endl;
  
}