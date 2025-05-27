#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> arr[101][101];
bool light[101][101];
bool visited[101][101];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int answer;



int main(){
    
    cin>>n>>m;
    
    for(int i=1;i<=m;i++){
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        arr[x][y].push_back({a,b});
    }

    queue<pair<int,int>>q;
    q.push({1,1});
    visited[1][1]=true;
    light[1][1]=true;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        // 스위치 누르기
        for (auto [a, b] : arr[curx][cury]) {
            if (!light[a][b]) {
                light[a][b] = true;
                //a,b 인접한곳에 방문한게 있으면 a,b도 큐에 넣기 (어차피 얘도 방문하게 될거기 때문에)
                for(int i=0;i<4;i++){
                    int nx = a+dx[i];
                    int ny = b+dy[i];
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                        if(visited[nx][ny]){
                            visited[a][b]=true;
                            q.push({a,b});
                            break;
                            
                        }

                    }
                }
            }
        }

        // 이동하기 (인접하고, 불켜진 방ㅇ으로만)
        for(int i=0;i<4;i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                if(!visited[nx][ny]&&light[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }

   
    }

    

     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(light[i][j]){
                answer++;

            }
        }

    }

    cout<<answer<<endl;




}