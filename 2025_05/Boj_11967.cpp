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

    // 인접한 애들만 스위치로 켤수 있음
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (auto [a, b] : arr[curx][cury]) {
            if (!light[a][b]) {
                light[a][b] = true;

                for(int i=0;i<4;i++){
                    int nx = a+dx[i];
                    int ny = b+dy[i];

                    // 이동은 상하좌우 인접, 방문은 했는데 스위치는 안켜진
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                        if(visited[nx][ny]){
                            visited[a][b]=true;
                            q.push({a,b});
                           
                            
                        }

                    }
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