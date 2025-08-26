#include <bits/stdc++.h>

using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int sx,sy;
int ex,ey;
int r,c;
bool visited[101][101];

struct Node{
    int r;
    int c;
    int cnt;
};

bool isBorder(int x,int y,vector<string> board){
    if(x<0||x>=r||y<0||y>=c){
        return true;
    }
    if(board[x][y]=='D'){
        return true;
    }
    return false;
}

int solution(vector<string> board) {
    int answer = 0;
    r = board.size();
    c = board[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]=='R'){
                sx=i;
                sy=j;
            }
        }
    }
    
    visited[sx][sy]=true;
    queue<Node>q;
    q.push({sx,sy,0});
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.r;
            int ny = cur.c;
            while(1){
                int nnx = nx+dx[i];
                int nny = ny+dy[i];
                if(isBorder(nnx,nny,board)){
                    break;
                }
                nx = nnx;
                ny = nny;
            }
            
            if(board[nx][ny]=='G'){
                return cur.cnt+1;
            }
            if(!visited[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx,ny,cur.cnt+1});
            }
        }
    }
    
    return -1;
}