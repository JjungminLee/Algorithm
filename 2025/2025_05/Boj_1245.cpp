#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[101][101];
bool visited[101][101];
int ans;
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};

bool bfs(int x,int y){
    int std = arr[x][y];
    queue<pair<int,int>>q;
    visited[x][y]=true;
    bool isHighLand=false;
    q.push({x,y});
    
   
    while(!q.empty()){
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nx =curx+dx[i];
            int ny =cury+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m){
                if(arr[nx][ny]>std){
                    isHighLand=true;
                }
                if(!visited[nx][ny]){
                    if(arr[nx][ny]==std){
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }

    return isHighLand;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                if(!bfs(i,j)){
                    ans++;
                }
            }
        }

    }

    cout<<ans<<endl;


}