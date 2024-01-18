#include <bits/stdc++.h>
using namespace std;

int R;
int C;
vector<vector<char>> v;
int dirX[]={-1,1,0,0};
int dirY[]={0,0,-1,1};
queue<pair<int,int>> waterQueue;
queue<pair<int,int>> q;
int ans;
//물이 차있는 지역은 * 돌은 x 
// 물은 돌을 통과할 수 없다 물도 소굴은 통과할 수 없다

void bfs(){
    // 물이 먼저 차오르고


    // 고슴도치가 더이상 이동할 수 없을 때까지
    while(!q.empty()){
    
        int waterSize = waterQueue.size();
        for(int i=0;i<waterSize;i++){
            int x = waterQueue.front().first;
            int y = waterQueue.front().second;
            waterQueue.pop();
            for(int j=0;j<4;j++){
                int newX = x+dirX[j];
                int newY = y+dirY[j];
                if(newX>=0&&newX<R&&newY>=0&&newY<C){
                    if(v[newX][newY]=='.'){
                        waterQueue.push({newX,newY});
                        v[newX][newY]='*';
                    }
                }
            }
        }

        int hedgehogSize = q.size();
        for(int i=0;i<hedgehogSize;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int newX = x+dirX[j];
                int newY = y+dirY[j];
                if(newX>=0&&newX<R&&newY>=0&&newY<C){
                    if(v[newX][newY]=='D'){
                            
                            ans++;
                            cout<<ans;
                            return;
                    }
                    else if(v[newX][newY]=='.'){
                        q.push({newX,newY});
                        v[newX][newY]='S';
                        
                    }
                }
            }
        }
        ans++;
    }
    cout<<"KAKTUS"<<endl;
}
int main(){
    cin>>R>>C;
    v = vector<vector<char>>(R, vector<char>(C));
    waterQueue={};
    q={};


    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>v[i][j];         
            if(v[i][j]=='*'){
                waterQueue.push({i,j});
            }
            if(v[i][j]=='S'){
                q.push({i,j});
            }
            
        }

    }

    bfs();


}