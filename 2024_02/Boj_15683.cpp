#include <bits/stdc++.h>

using namespace std;
int N,M;
int arr[9][9];
// 우 상 좌 하
int dirX[4]={0,-1,0,1};
int dirY[4]={1,0,-1,0};
vector<pair<int,int>> cctv;
int ans = INT_MAX;
int cnt;

void check(int x,int y,int dir){
    dir%=4;
    while(true){
        // 해당 방향으로 조건 만족하기 전까지 쭉 이동
        int nx = x+dirX[dir];
        int ny = y+dirY[dir];
        cout<<nx<<" "<<ny<<" "<<arr[nx][ny]<<endl;
        if(nx<0||nx>=N||ny<0||ny>=M){
            //범위 넘어감
            return;
        }
        if(arr[nx][ny]==6){
            //벽
            return;
        }
        if(arr[nx][ny]!=0){
            continue;
        }
        // cctv 감시 영역
        arr[nx][ny]=-1;
    }
}

void dfs(int idx){
   
    if(idx==cnt){
        int res=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j]==0){
                    res++;
                }
            }
        }
        ans=min(ans,res);
        cout<<"ans: "<<ans<<endl;
        return;
    }
    // 상하좌우 회전을 갈긴다
    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int backup[8][8];

    // 우 상 좌 하 순으로!
    for(int dir=0;dir<4;dir++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                backup[i][j]=arr[i][j];
            }
        }
        if(arr[x][y]==1){
            check(x,y,dir); // 0 
        }
        if(arr[x][y]==2){
            check(x,y,dir);
            check(x,y,dir+2);
        }
        if(arr[x][y]==3){
            check(x,y,dir);
            check(x,y,dir+1);
        }
        if(arr[x][y]==4){
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
        }
        if(arr[x][y]==5){
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
            check(x,y,dir+3);
        }
        dfs(idx+1);
        // 원복시켜주기!
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                arr[i][j]=backup[i][j];
            }
        }
    }
   


}


int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            if(1<=arr[i][j]&&arr[i][j]<=5){
                cctv.push_back({i,j});
            }
        }
    }
    cnt=cctv.size();
    dfs(0);
    cout<<ans<<endl;
}