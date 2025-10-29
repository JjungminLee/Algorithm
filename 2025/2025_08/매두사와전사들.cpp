#include<bits/stdc++.h>
using namespace std;

#define MAX (355)
#define VISION (1)
#define WARRIORS (2)
#define SCOPE_WALL (3) 
#define STONE (4)
#define WALL (1)

#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3

#define STRAIGHT (1)

struct WARRIOR{
    int r;
    int c;
    bool death;
};

struct ANSWER{
    int distance;
    int stone;
    int attack;
};

struct RC{
    int r;
    int c;
};

int N,M;
int sr,sc;
int er,ec;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int maps[MAX][MAX];
bool visited[MAX][MAX];
int scope[MAX][MAX]; // 시선처리

RC before[MAX][MAX];
RC positions[MAX*MAX];
RC medusa;

int pcnt; // 경로의 총 길이

WARRIOR warriors[MAX];
ANSWER answer;

void input(){
    cin>>N>>M;
    cin>>sr>>sc>>er>>ec;
    sr+=1;
    sc+=1;
    er+=1;
    ec+=1;
    pcnt=0;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        warriors[i]={a+1,b+1,false};
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>maps[i][j];
        }
    }
}

void diagnol(int r,int c,int dir,int ndir,int val){
    int step=1;
    while(1){
        int curr,curc;
        // 아래 방향, 아래에서 왼쪽방향으로
        curr = r+(dx[dir]+dx[ndir])*step;
        curc = c+(dy[dir]+dy[ndir])*step;
        if(curr<1||curr>N||curc<1||curc>N) break;
        scope[curr][curc]=val;

        // 왼쪽으로 틀고 그 밑에 전부다 val로 채워주기

        while(1){
            int nr = curr+dx[dir];
            int nc = curc+dy[dir];

            if (nr < 1 || nr > N || nc < 1 || nc > N) break;  
            scope[nr][nc]=val;

            curr = nr;
            curc = nc;
        }
        step++;  
    }
    

}

void leftLook(int r,int c,int dir,int val){
    int changeDir[4] ={2,3,1,0};
    int leftDir = changeDir[dir]; 

    diagnol(r,c,dir,leftDir,val);

}

void rightLook(int r,int c,int dir,int val){
    int changeDir[4] ={3,2,0,1};
    int rightDir = changeDir[dir]; 

    diagnol(r,c,dir,rightDir,val);

}

void straight(int r,int c,int dir,int val){
    int curr,curc;
    curr=r;
    curc=c;
    while(1){
        int nnr,nnc;
        nnr = curr+dx[dir];
        nnc = curc+dy[dir];
        if(nnr>=1&&nnr<=N&&nnc>=1&&nnc<=N){
            scope[nnr][nnc] = val;
            curr=nnr;
            curc=nnc;
        }else{
            break;
        }
    }

}



void BFS(){
    queue<RC>q;
    // 최단경로가 여러개면 상하좌우 순서대로 되어야하기에 경로의 trace가 필요
    // before과 positions를 사용하여 이 역할을 함
    visited[sr][sc]=true;
    before[sr][sc].r=-1;
    before[sr][sc].c=-1;
    q.push({sr,sc});
    while(!q.empty()){
        RC cur = q.front();
        int cr = cur.r;
        int cc = cur.c;
        q.pop();
        if(cr==er&&cc==ec){
            pcnt=0;
        
            positions[pcnt++]={cr,cc};

            while(1){
                int br = before[cr][cc].r;
                int bc = before[cr][cc].c;
                if(br==sr&&bc==sc) break;
                positions[pcnt++]={br,bc};
                cr = br;
                cc = bc;
            }
            // 배열에 있는 것을 뒤집음
            for(int i=0;i<(pcnt/2);i++){
                RC tmp = positions[i];
                positions[i]=positions[pcnt-1-i];
                positions[pcnt-1-i]=tmp;
            }
            return;
   
        }

        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=1&&nr<=N&&nc>=1&&nc<=N){
                if(!visited[nr][nc]&&maps[nr][nc]!=WALL){
                    q.push({nr,nc});
                    visited[nr][nc] = true;
                    before[nr][nc] = cur;
                }
            }
        }


    }
    

}

void moveMedusa(int idx){
    medusa = positions[idx];
    for(int i=0;i<M;i++){
        if(warriors[i].death) continue;
        int wr,wc;
        wr = warriors[i].r;
        wc = warriors[i].c;
        if(wr==medusa.r&&wc==medusa.c){
            warriors[i].death=true;
        }
    }
}

int countStoneWarriror(int dir){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scope[i][j]=0;
        }
    }
    int mr,mc;
    mr = medusa.r;
    mc = medusa.c;
    straight(mr,mc,dir,STRAIGHT);
    leftLook(mr,mc,dir,DIR_LEFT);
    rightLook(mr,mc,dir,DIR_RIGHT);
    for(int i=0;i<M;i++){
        if(warriors[i].death) continue;
        int wr = warriors[i].r;
        int wc = warriors[i].c;

        if(scope[wr][wc]==STRAIGHT) straight(wr,wc,dir,0);
        else if(scope[wr][wc]==DIR_LEFT){
            straight(wr,wc,dir,0);
            leftLook(wr,wc,dir,0);
        }else if(scope[wr][wc]==DIR_RIGHT){
            straight(wr,wc,dir,0);
            rightLook(wr,wc,dir,0);
        }
    }

    // 돌로 변한 전사들
    int cnt = 0;
    for(int i=0;i<M;i++){
        if(warriors[i].death) continue;
        int wr,wc;
        wr = warriors[i].r;
        wc = warriors[i].c;
        // 0 인경우 메두사의 시선이 닿지 않는곳
        if(scope[wr][wc]!=0) cnt++;

    }

    return cnt;

}

void lookAt(){
    int maxCnt= 0, maxDir=0;
    for(int i=0;i<4;i++){
        int tmp = countStoneWarriror(i);
        if(maxCnt<tmp){
            maxCnt = tmp;
            maxDir = i;
        }
    }
    // maxDir기준으로 scope세팅
    countStoneWarriror(maxDir);
    answer.stone = maxCnt;

}

int checkRow(WARRIOR w){
    int mr = medusa.r;
    int wr = w.r;
    // mr>wr -> 메두사가 아래에
    // mr == wr -> 같은행
    // mr < wr -> 메두사가 위에
    return mr-wr;
}

int checkCol(WARRIOR w){
    int mc = medusa.c;
    int wc = w.c;
    // mr>wr -> 메두사가 아래에
    // mr == wr -> 같은행
    // mr < wr -> 메두사가 위에
    return mc-wc;
}

// 메두사가 바라보는 시선에 포함되는지
bool checkScope(WARRIOR w,int dir){
    int nr = w.r + dx[dir];
    int nc = w.c + dy[dir];
    if (nr < 1 || nr > N || nc < 1 || nc > N) return false;
    return scope[nr][nc] == 0;   
}

void moveWarrior(bool first){

    for(int i=0;i<M;i++){
        WARRIOR w = warriors[i];
        if(w.death) continue;
        if(scope[w.r][w.c]!=0) continue;
        //전사들을 메두사에 가까워지게 구현해야함 => 단순히 bfs가 아님
        int upDown = checkRow(w);
        int leftRight = checkCol(w);
        int direction = -1;

        // 메두사 향해서 이동하므로 격자밖 조건은 필요없음
        if(first){
            // 상하좌우
            if(upDown<0&&checkScope(w,DIR_UP)) direction = DIR_UP;
            else if(upDown>0&&checkScope(w,DIR_DOWN)) direction = DIR_DOWN;
            else if (leftRight<0&&checkScope(w,DIR_LEFT)) direction = DIR_LEFT;
            else if (leftRight>0&&checkScope(w,DIR_RIGHT)) direction = DIR_RIGHT;

        }else{
            // 좌우상하
            if (leftRight<0&&checkScope(w,DIR_LEFT)) direction = DIR_LEFT;
            else if (leftRight>0&&checkScope(w,DIR_RIGHT)) direction = DIR_RIGHT;
            else if(upDown<0&&checkScope(w,DIR_UP)) direction = DIR_UP;
            else if(upDown>0&&checkScope(w,DIR_DOWN)) direction = DIR_DOWN;
        }
        
        if(direction==-1) continue;
        int nr,nc;
        nr = w.r+dx[direction];
        nc = w.c+dy[direction];

        warriors[i].r = nr;
        warriors[i].c = nc;

        answer.distance++;

        if(nr==medusa.r&&nc==medusa.c){
            answer.attack++;
            warriors[i].death=true;
        }

    }
}

void simulate(){
    if(pcnt==0){
        cout<<-1<<"\n";
        return;
    }
    // 공원에 도착했을떄 0을 출력해야해서 pcnt-1까지
    for(int i=0;i<pcnt-1;i++){
        answer.distance = answer.stone = answer.attack = 0;
        moveMedusa(i);
        lookAt();
        moveWarrior(true);
        moveWarrior(false);
        cout<<answer.distance<<" "<<answer.stone<<" "<<answer.attack<<"\n";

    }
    cout<<0<<"\n";
}

int main(){
    input();
    BFS();
    simulate();

}