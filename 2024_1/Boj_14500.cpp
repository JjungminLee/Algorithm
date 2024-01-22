#include <bits/stdc++.h>
using namespace std;
// depth가 3일때!
int N;
int M;
int ans=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int arr[501][501];
int visits[501][501];

void shape1(int x,int y){
    int cnt=0;
   cnt+=arr[x][y];
   for(int i=y-1;i<=y+1;i++){
    cnt+=arr[x+1][i];
   }
   ans=max(cnt,ans);
   

}
void shape2(int x,int y){
    int cnt=0;
   cnt+=arr[x][y];
   for(int i=y-1;i<=y+1;i++){
    cnt+=arr[x-1][i];
   }
   ans=max(cnt,ans);
   

}

void shape3(int x,int y){
  int cnt=0;
   cnt+=arr[x][y];
   for(int i=x-1;i<=x+1;i++){
    cnt+=arr[i][y+1];
   
   }
   ans=max(cnt,ans);

}

void shape4(int x,int y){
    int cnt=0;
   cnt+=arr[x][y];
   for(int i=x-1;i<=x+1;i++){
        cnt+=arr[i][y-1];
    
   }
   ans=max(cnt,ans);

}

void dfs(int x,int y,int depth,int cnt){
    if(depth==3){
        ans=max(ans,cnt);
        return;

    }else{
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(!visits[nx][ny]){
                    visits[nx][ny]=true;
                    dfs(nx,ny,depth+1,cnt+arr[nx][ny]);
                    visits[nx][ny]=false;
                }
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            // memset(visits,false,sizeof(visits));
            visits[i][j]=true;
            dfs(i,j,0,arr[i][j]);
            visits[i][j]=false;
            if(j-1>=0&&j+1<M&&i+1<N&&j-1<M&&j+1>=0&&i+1>=0){
                shape1(i,j);

            }
            if(j-1>=0&&j+1<M&&i-1>=0&&j-1<M&&j+1>=0&&i-1<N){
                shape2(i,j);

            }
            if(i-1>=0&&i+1<N&&j+1<M&&i-1<N&&i+1>=0&&j+1>=0){
                shape3(i,j);

            }
            if(i-1>=0&&i+1<N&&j-1>=0&&i-1<N&&i+1>=0&&j-1<M){
                shape4(i,j);
            }
            
            
            
            
        }
    }
    cout<<ans;

}