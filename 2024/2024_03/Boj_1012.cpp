#include <bits/stdc++.h>


using namespace std;

int T,M,N,K;
int arr[51][51];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int ans;
bool visits[51][51];


void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});

    while(!q.empty()){
        int curX=q.front().first;
        int curY=q.front().second;
       
        q.pop();
        for(int i=0;i<4;i++){
            int nx=curX+dx[i];
            int ny=curY+dy[i];
            if(nx>=0&&nx<M&&ny>=0&&ny<N){
                if(!visits[nx][ny]&&arr[nx][ny]==1){
                    q.push({nx,ny});
                    visits[nx][ny]=true;
                }
            }
        }
    }
    ans++;
   
   

}
int main(){
    cin>>T;

    for(int l=0;l<T;l++){
            ans=0;
            cin>>M>>N>>K;
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    arr[i][j]=0;
                    visits[i][j]=false;
                }
            }
            for(int i=0;i<K;i++){
                int X,Y;
                cin>>X>>Y;
                arr[X][Y]=1;
            }
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    if(!visits[i][j]&&arr[i][j]==1){
                        bfs(i,j);
                    }
                }
            }
            cout<<ans<<endl;
    }
}