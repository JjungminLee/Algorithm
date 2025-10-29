#include<bits/stdc++.h>

using namespace std;

int N;
int M;
int T;
int maps[105][105];
bool visited[105][105][2];
int ans = INT_MAX;

struct Node{
    int r;
    int c;
    int curTime;
    bool gram;
};

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M>>T;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>maps[i][j];
        }
    }

    queue<Node>q;
    q.push({0,0,0,false});
    visited[0][0][0]=true;

    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        
        if(cur.r==N-1&&cur.c==M-1){
            ans=min(ans,cur.curTime);
            continue;
        }
        
        if(cur.curTime>T) continue;

        for(int i=0;i<4;i++){
            int nr = cur.r+dr[i];
            int nc = cur.c+dc[i];
            if(nr>=0&&nr<N&&nc>=0&&nc<M){
                if(!visited[nr][nc][cur.gram]){
                    if(cur.gram){
                        visited[nr][nc][cur.gram]=true;
                        q.push({nr,nc,cur.curTime+1,cur.gram});
                    }else{
                        if(maps[nr][nc]==1) continue;
                        if(maps[nr][nc]==2){
                            q.push({nr,nc,cur.curTime+1,true});
                            visited[nr][nc][cur.gram]=true;
                        }else if(maps[nr][nc]==0){
                            q.push({nr,nc,cur.curTime+1,cur.gram});
                            visited[nr][nc][cur.gram]=true;
                        }
                    }
                }
            }
        }

    }

    if(ans<=T){
        cout<<ans<<"\n";
    }else{
        cout<<"Fail"<<"\n";
    }

}