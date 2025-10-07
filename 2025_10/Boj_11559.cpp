#include<bits/stdc++.h>

using namespace std;
#define R (12)
#define C (6)

char maps[R][C];
int ans;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void input(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>maps[i][j];
        }
    }

}

bool bfs(int r,int c,char ch){
    queue<pair<int,int>>q;
    bool visited[R][C]={false,};

    visited[r][c]=true;
    q.push({r,c});
    int cnt = 1;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C){
                if(!visited[nx][ny]&&maps[nx][ny]==ch){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                    cnt++;
                }
            }

        }
    }
    return cnt>=4?true:false;
}

void removeBfs(int r,int c,char ch){
    queue<pair<int,int>>q;
    bool visited[R][C]={false,};

    visited[r][c]=true;
    maps[r][c]='.';
    q.push({r,c});
    int cnt = 0;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C){
                if(!visited[nx][ny]&&maps[nx][ny]==ch){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                    maps[nx][ny]='.';
                }
            }

        }
    }
}

// 떨어지기
void move() {
    for (int j = 0; j < C; j++) {
        vector<char> temp;
        for (int i = R - 1; i >= 0; i--) { 
            if (maps[i][j] != '.') temp.push_back(maps[i][j]);
        }

        int idx = R - 1;
        for (char ch : temp) {
            maps[idx--][j] = ch;
        }
        for (int i = idx; i >= 0; i--) {
            maps[i][j] = '.';
        }
    }
}


void simulate(){
    while(1){
        bool popped = false;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(maps[i][j]!='.'&&bfs(i,j,maps[i][j])){
                    removeBfs(i,j,maps[i][j]);
                    popped=true;
                }
            }
        }
        // 전부다 빈칸이고 연쇄할게 없을때
        if(!popped) break;
        ans++;
        move();

    }
}

int main(){
    input();
    simulate();
    cout<<ans<<"\n";
}