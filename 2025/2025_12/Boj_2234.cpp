#include<bits/stdc++.h>

using namespace std;

int arr[55][55];
bool visited[55][55];
// 상 하 좌 우
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int wall[4]={2,8,1,4};
int N,M;
int maxSize = 0;

vector<int>v;

void bfs(int sx,int sy){

    queue<pair<int,int>>q;
    visited[sx][sy]=true;
    q.push({sx,sy});
    int size=1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int cx = cur.first;
        int cy = cur.second;

        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(arr[cx][cy]&wall[i]) continue; // i번째 비트에 1이 있는지 파악
            if(nx<0||nx>=M||ny<0||ny>=N) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
            size++;
        }

    }
    v.push_back(size);
}

void deleteBfs(int sx,int sy){
    queue<pair<int,int>>q;
    visited[sx][sy]=true;
    q.push({sx,sy});
    int size=1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int cx = cur.first;
        int cy = cur.second;

        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];

            if(arr[cx][cy]&wall[i]) continue; // i번째 비트에 1이 있는지 파악
            if(nx<0||nx>=M||ny<0||ny>=N) continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx,ny});
            size++;
        }

    }
    maxSize = max(maxSize,size);
}

int main(){
    cin>>N>>M;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                bfs(i,j);
            }
        }
    }

    cout<<v.size()<<"\n";
    sort(v.begin(),v.end());
    cout<<v[v.size()-1]<<"\n";

    memset(visited, false, sizeof(visited));

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                for(int k=0;k<4;k++){
                    // 벽이 있다면 제거 하고 bfs돌려보기
                    if(arr[i][j]&wall[k]){
                        int temp = arr[i][j];
                        arr[i][j] &= ~wall[k];
                        memset(visited, false, sizeof(visited));
                        deleteBfs(i,j);
                        arr[i][j]=temp;
                    }
                
                }
                
            }
        }
    }

    cout<<maxSize<<"\n";


}