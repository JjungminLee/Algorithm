#include<bits/stdc++.h>
using namespace std;

#define MAX (45)
#define BLANK (0)
#define TRAP (1)
#define WALL (2)


int L,N,Q;
struct KNIGHT{
    int r;
    int c;
    int h;
    int w;
    int strength;
    int isAlive;
    int initStrength;
};

struct RC{
    int r;
    int c;
    int idx;
};

KNIGHT kV[MAX];
int maps[MAX][MAX]; // 함정과 벽
int tmpMaps[MAX][MAX];// 기사들의 id를 기록

int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

bool isRange(int r,int c){
    if(r>=1&&r<=L&&c>=1&&c<=L) return true;
    return false;
}

void setMap(){
    for(int r=1;r<=L;r++){
        for(int c=1;c<=L;c++){
            tmpMaps[r][c]=0;
        }
    }
    for(int i=1;i<=N;i++){
        int kr = kV[i].r;
        int kc = kV[i].c;
        int kw = kV[i].w;
        int kh = kV[i].h;
        if(!isRange(kr,kc)) continue;
        // 죽은 경우 뺌
        if(!kV[i].isAlive) continue;
        for(int r=kr;r<kr+kh;r++){
            for(int c = kc;c<kc+kw;c++){
                 tmpMaps[r][c] = (i)*10;//기사의 id
            }
        }
    }
}

// 기사들이 움직일 수 있냐 없냐
void bfs(int idx,int dir){
    if(kV[idx].strength<=0) return;
    queue<RC>q;
    bool visited[MAX][MAX]={false,};
    int cr = kV[idx].r;
    int cc = kV[idx].c;
    int ch = kV[idx].h;
    int cw = kV[idx].w;
    bool check[MAX]={0,};

    check[idx]=true;

    // 기사 idx 만큼 영역을 큐에 푸쉬
    for(int r=cr;r<(cr+ch);r++){
        for(int c=cc;c<(cc+cw);c++){
            visited[r][c]=true;
            q.push({r,c,idx});
        }
    }
    // 움직일 수 있나 없나를 bfs로 판단
    while(!q.empty()){
        int nr = q.front().r+dr[dir];
        int nc = q.front().c+dc[dir];
        int kIdx = q.front().idx;
        q.pop();
        if(!isRange(nr,nc)) return;
        // 벽을 만난 경우
        if(maps[nr][nc]==WALL) return;
        // 이미 방문 했거나 기사가 없는 칸
        if(visited[nr][nc]||tmpMaps[nr][nc]==BLANK) continue;
        
        // 이동한 곳에 또 기사가 있는 경우
        int another = tmpMaps[nr][nc]/10;
        int kr,kc,kh,kw;

        kr = kV[another].r;
        kc = kV[another].c;
        kw = kV[another].w;
        kh = kV[another].h;

        for(int r=kr;r<(kr+kh);r++){
            for(int c = kc;c<(kc+kw);c++){
                if(!visited[r][c]){
                    q.push({r,c,another});
                    visited[r][c]=true;
                }
            }
        }

        // 한칸 밀려난 병사들 기록
        check[another]=true;
    }


    for(int i=1;i<=N;i++){
        if(!check[i]) continue;

        // 밀려난 애들 밀린 r,c 세팅
        kV[i].r = kV[i].r+dr[dir];
        kV[i].c = kV[i].c+dc[dir];

        // 명령을 받는 기사는 피해 안입음
        if(i==idx) continue;

        int kr,kc,kw,kh;
        kr = kV[i].r;
        kc = kV[i].c;
        kw = kV[i].w;
        kh = kV[i].h;

        for(int r=kr;r<(kr+kh);r++){
            for(int c = kc;c<(kc+kw);c++){
                if(maps[r][c]==TRAP){
                    kV[i].strength--;
                    if(kV[i].strength<=0){
                        kV[i].isAlive = false;
                    }
                }
            }
        }

    }


}

void simulate(int idx,int dir){
    setMap();
    bfs(idx,dir);
}

void input(){
    cin>>L>>N>>Q;
    for(int i=1;i<=L;i++){
        for(int j=1;j<=L;j++){
            cin>>maps[i][j];
        }

    }
    for(int i=1;i<=N;i++){
        int r,c,h,w,k;
        cin>>r>>c>>h>>w>>k;
        KNIGHT knight={0,};
        knight.r=r;
        knight.c=c;
        knight.h=h;
        knight.w=w;
        knight.strength=k;
        knight.isAlive=true;
        knight.initStrength=k;
        knight.initStrength = k;
        kV[i]=knight;
    }

}

int main(){

    input();
    for(int i=0;i<Q;i++){
        int idx,dir;
        cin>>idx>>dir;
        simulate(idx,dir);
    }
    int ans = 0;
     for(int i=1;i<=N;i++){
        if(kV[i].isAlive){
            ans+=kV[i].initStrength-kV[i].strength;
        }
    }
    cout<<ans<<"\n";
}