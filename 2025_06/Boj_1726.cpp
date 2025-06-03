#include<bits/stdc++.h>
using namespace std;

int arr[101][101];
bool visited[101][101][4];
int n,m;
// 동 서 남 북
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


struct Node{
    int x,y,dir,cnt;
};

int sx,sy,sd;
int ex,ey,ed;
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cin>>sx>>sy>>sd;
    cin>>ex>>ey>>ed;
    queue<Node>q;
    sx-=1;
    sy-=1;
    ex-=1;
    ey-=1;
    sd-=1;
    ed-=1;
    q.push({sx,sy,sd,0});
    visited[sx][sy][sd]=true;
    while(!q.empty()){
        int curx=q.front().x;
        int cury=q.front().y;
        int curd=q.front().dir;
        int cnt = q.front().cnt;
        q.pop();
        if(curx==ex&&cury==ey&&curd==ed){
            cout<<cnt<<endl;
            return 0;
        }
        int nx=0;
        int ny=0;
        // 전진하는 경우
        for(int i=1;i<=3;i++){
            nx=curx+dx[curd]*i;
            ny = cury+dy[curd]*i;
            if(nx>=0&&nx<m&&ny>=0&&ny<n){
                if(arr[nx][ny]==1){
                    // 중간에 벽 있으면 안됨
                    break;
                }
                if(!visited[nx][ny][curd]&&arr[nx][ny]==0){
                    q.push({nx,ny,curd,cnt+1});
                    visited[nx][ny][curd]=true;
                }
            }
        }
        // 방향 전환 하는 경우 (이동은 아님, 현재 위치)
        for(int i=0;i<4;i++){
            if(i==curd) continue;
            // 동 <-> 서 , 남 <-> 북 이면 2번
            int rotateCost=0;
            if(curd/2==i/2){
                rotateCost=2;
            }else{
                rotateCost=1;
            }

            if(!visited[curx][cury][i]){// nx ny i가 아님!
                q.push({curx,cury,i,cnt+rotateCost});
                visited[curx][cury][i]=true;
            }
        }

    }

}