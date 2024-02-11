#include <bits/stdc++.h>

using namespace std;

int N;
int arr[21][21];


int dy[] = {-1, 0, 0, 1}, dx[] = {0, -1, 1, 0};

int sharkX,sharkY;


struct Fish
{
    int y, x, dist;
    bool operator<(const Fish &b) const
    {
        if (dist == b.dist)
        {
            if (y == b.y)
                return x > b.x;
            return y > b.y;
        }
        return dist > b.dist;
    }
};


queue<Fish>q; // 방문할 수 있는 물고기


int bfs(){
    int ans=0;
    int sharkSize=2;//상어 사이즈
    int eat=0;//얼마나 먹었는지

    while(true){
      
        priority_queue<Fish> pq;
        vector<vector<bool>> visits(N, vector<bool>(N));
        // 매턴 마다 우선순위큐와 visits배열 초기화 해야
        // 현재 턴 -> 다 돌고 + 먹을수 있는 물고기까지 넣음
        while(!q.empty()){
            Fish fish=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx=fish.x+dx[i];
                int ny=fish.y+dy[i];
                if(nx<0||nx>=N||ny<0||ny>=N){
                    continue;
                }
                if(visits[ny][nx]||arr[ny][nx]>sharkSize){
                    continue;
                }
                // 방문할수 있는 물고기
                visits[ny][nx]=true;
                q.push({ny,nx,fish.dist+1});
                //먹을 수 있는물고기
                 if(arr[ny][nx]!=0&&arr[ny][nx]<sharkSize){
                    pq.push({ny,nx,fish.dist+1});
                }
            }
        }
        
        // 먹을 수 있는 물고기 없다면 끝내줌
 
        if(pq.empty()){
            break;
        }
        Fish fish=pq.top();
        int fx=fish.x;
        int fy=fish.y;
        int fd=fish.dist;
        eat+=1;
        if(eat==sharkSize){
                sharkSize++;
                eat=0;
        }
        // 먹이 위치로 이동
        arr[fy][fx]=0;
        q.push({fy,fx,0});
        ans+=fd;
    }
    return ans;
    

}


int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                arr[i][j]=0;
                q.push({i,j,0});
            }
        }
    }

    cout<<bfs()<<endl;
    return 0;

    
}