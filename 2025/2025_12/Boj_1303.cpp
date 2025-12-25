#include<bits/stdc++.h>

using namespace std;

int n,m;
char arr[105][105];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool visited[105][105];
int wcnt;
int bcnt;

void bfs(int x,int y){
    queue<pair<int,int>>q;
    visited[x][y]=true;
    char ch = arr[x][y];
    int cnt = 1;
    q.push({x,y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0&&nx<m&&ny>=0&&ny<n){
                if(!visited[nx][ny]&&arr[nx][ny]==ch){
                    visited[nx][ny]=true;
                    cnt++;
                    q.push({nx,ny});
                }
            }
        }
    }
    cnt*=cnt;

    if(ch=='W'){
        wcnt+=cnt;
    }else if(ch=='B'){
        bcnt+=cnt;
    }

}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        string str;
        cin>>str;
        for(int j=0;j<n;j++){
            arr[i][j]=str[j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                bfs(i,j);
            }
        }
    }

    cout<<wcnt<<" "<<bcnt<<"\n";

}