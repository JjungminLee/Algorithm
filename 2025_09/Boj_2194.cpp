#include<bits/stdc++.h>
using namespace std;

#define TRAP (2)
#define MAX (505)

int N,M;
int A,B;
int K;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int maps[MAX][MAX];
bool visited[MAX][MAX];

struct RC{
    int r;
    int c;
    int cnt;
};

RC startNode;
RC endNode;

bool isTrap(int r,int c){
    for(int i=r;i<r+A;i++){
        for(int j=c;j<c+B;j++){
            if(maps[i][j]==TRAP){
                return false;
            }

        }
    }
    return true;
}

bool isEnd(int x,int y){
    if(endNode.r==x && endNode.c==y){
        return true;
    }
    return false;
}

bool isInRange(int x,int y){
    // 로봇이 A*B만큼 차지해야하고 그게 maps범위 안에 있어야!
    if(1<=x&&x<=N-A+1&&1<=y&&y<=M-B+1){
        return true;
    }
    return false;
}

int main(){
    int ans = -1;

    cin>>N>>M>>A>>B>>K;
    for(int i=0;i<K;i++){
        int r,c;
        cin>>r>>c;
        maps[r][c]=TRAP;
    }
    queue<RC>q;
    cin>>startNode.r>>startNode.c;
    cin>>endNode.r>>endNode.c;
    if(isEnd(startNode.r,startNode.c)){
        cout<<0<<"\n";
        return 0;
    }
    visited[startNode.r][startNode.c]=true;
    q.push({startNode.r,startNode.c,0});
    
    while(!q.empty()){
        RC cur = q.front();
        q.pop();
        if(isEnd(cur.r,cur.c)){
            ans=cur.cnt;
            break;
        }

        for(int i=0;i<4;i++){
            int nr = cur.r+dx[i];
            int nc = cur.c+dy[i];
            if(!isInRange(nr,nc)) continue;
            if(!isTrap(nr,nc)) continue;
            if(visited[nr][nc]) continue;
            q.push({nr,nc,cur.cnt+1});
            visited[nr][nc]=true;
        }
    }
    
    cout<<ans<<endl;

}