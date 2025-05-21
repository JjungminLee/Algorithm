#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool fireVisited[1001][1001];
bool visited[1001][1001];
char arr[1001][1001];
int n;

int main(){
    cin>>n;
    while(n--){
        int w,h;
        cin>>w>>h;
        
        queue<pair<int,int>>fq;
        queue<pair<int,int>>q;
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                arr[i][j]=0;
                fireVisited[i][j]=false;
                visited[i][j]=false;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='*'){
                    fq.push({i,j});
                    fireVisited[i][j]=true;
                }
                if(arr[i][j]=='@'){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }

        bool escape=false;
        int cnt=0;

        
        while(!q.empty()&&!escape){
            cnt++;
            // 불 이동
            // 현재 단계에서만 불이 퍼져야함 (큐에 있는 모든 위치를 소진하면 안됨 왜냐면 bfs하면서 계속 push돼서)
            int fsize=fq.size();
            for(int j=0;j<fsize;j++){
                int fx=fq.front().first;
                int fy=fq.front().second;
                fq.pop();
                for(int i=0;i<4;i++){
                    int nfx = fx+dx[i];
                    int nfy=fy+dy[i];
                    if(nfx>=0&&nfx<h&&nfy>=0&&nfy<w){
                        if(!fireVisited[nfx][nfy]&&arr[nfx][nfy]!='#'){
                            fq.push({nfx,nfy});
                            fireVisited[nfx][nfy]=true;
                            arr[nfx][nfy]='*';
                        }
                    }
                }
            }

            // 상근 이동
            //현재 단계에서만 상근이가 이동해야
            int ssize = q.size();
            for(int j=0;j<ssize;j++){

                int sx = q.front().first;
                int sy = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int nsx=sx+dx[i];
                    int nsy = sy+dy[i];
                    //상근이가 이동하려는 곳이 범위 바깥이면 탈출 성공
                    if(nsx<0||nsx>=h||nsy<0||nsy>=w){
                        escape=true;
                        break;
                       
                    }
                    if(nsx>=0&&nsx<h&&nsy>=0&&nsy<w){
                       
                        if(!visited[nsx][nsy]&&arr[nsx][nsy]=='.'){
                            arr[nsx][nsy]='@';
                            q.push({nsx,nsy});
                            visited[nsx][nsy]=true;
                        }

                    }
                }
                
            }
            

        }
       
        if(escape){
            cout<<cnt<<endl;
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }

        
    }

}