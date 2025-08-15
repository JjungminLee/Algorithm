#include<bits/stdc++.h>
using namespace std;

int w,h;

char arr[101][101];
long long dist[101][101][4];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct Node{
    long long cnt;
    int x;
    int y;
    int prevIdx;

    bool operator<(const Node& other) const{
        return cnt>other.cnt;
    }
};

bool isSwitch(int curIdx,int prevIdx){
    int prev = prevIdx<2?0:1;
    int cur = curIdx<2?0:1;
    return prev!=cur;
}


vector<pair<int,int>>v;
int main(){
    cin>>w>>h;
    string str;
    for(int i=0;i<h;i++){
        cin>>str;
        for(int j=0;j<w;j++){
            arr[i][j]=str[j];
            if(arr[i][j]=='C'){
                v.push_back({i,j});
            }
        }
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            for(int k=0;k<4;k++){
                dist[i][j][k]=INT_MAX;
            }
        }
    }
    int sx=v[0].first;
    int sy = v[0].second;
    for(int i=0;i<4;i++){
        dist[sx][sy][i]=0;
    }
     // 최소 개수 순, 좌표
    priority_queue<Node>pq;
    for(int i=0;i<4;i++){
        pq.push({0,sx,sy,i});
    }

    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            int nx = cur.x+dx[i];
            int ny = cur.y+dy[i];
            if(nx>=0&&nx<h&&ny>=0&&ny<w&&arr[nx][ny]!='*'){
                int add = isSwitch(i,cur.prevIdx)?1:0;
                if(dist[nx][ny][i]>dist[cur.x][cur.y][cur.prevIdx]+add){
                    dist[nx][ny][i]=dist[cur.x][cur.y][cur.prevIdx]+add;
                    pq.push({dist[cur.x][cur.y][cur.prevIdx]+add,nx,ny,i});
                }
            }
            
        }
    
    }
    long long ans = 1e18;
    for(int d=0;d<4;d++){
        ans = min(dist[v[1].first][v[1].second][d],ans);
    }
    cout<<ans<<endl;

}