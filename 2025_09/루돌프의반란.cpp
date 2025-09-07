#include<bits/stdc++.h>
using namespace std;

#define MAX (60)
#define RUDOLF (99)

struct Rudolf{
    int r;
    int c;
    int score;
};

struct Santa{
    int idx;
    int stun;
    bool isDie;
    int r;
    int c;
    int score;
};


int N,M,P,C,D;
int Rr,Rc;
int maps[MAX][MAX];
Santa santas[MAX];
Rudolf rudolf;
int rdx[8]={-1,1,0,0,-1,-1,1,1};
int rdy[8]={0,0,-1,1,-1,1,-1,1};

// 상우하좌
int sdx[4]={-1,0,1,0};
int sdy[4]={0,1,0,-1};

int getDistance(int r1,int c1,int r2,int c2){
    return (r1-r2)*(r1-r2)+(c1-c2)*(c1-c2);
}

bool isInRange(int r,int c){
    if(r>=1&&r<=N&&c>=1&&c<=N) return true;
    return false;
}

int getNearSantaIndex(){

    int santaIndex=0;
    int minDistance=INT_MAX;
    //r좌표가 큰 -> c좌표가 큰
    for(int r=N;r>=1;r--){
        for(int c=N;c>=1;c--){
            if(maps[r][c]==0||maps[r][c]==RUDOLF) continue;
            int dist = getDistance(rudolf.r,rudolf.c,r,c);
            if(dist<minDistance){
                minDistance = dist;
                santaIndex = maps[r][c];
            }
        }
    }
    return santaIndex;
}


int getRudolfDirection(int santaIndex){
    int dir = -1;
    int minDist = INT_MAX;

    Santa santa = santas[santaIndex];

    for(int i=0;i<8;i++){
        int nr = rudolf.r+rdx[i];
        int nc = rudolf.c+rdy[i];
        if(!isInRange(nr,nc)) continue;

        int dist = getDistance(nr,nc,santa.r,santa.c);
        if(dist<minDist){
            minDist = dist;
            dir = i;
        }
    }

    return dir;

}

void interaction(int santaIndex,int dir,bool isRudolf){
    Santa startSanta = santas[santaIndex];

    // 연쇄적으로 밀려날 산타
    int candidate[MAX]={0,};

    int cnt = 0;
    candidate[cnt++]=santaIndex;
    int nr = startSanta.r;
    int nc= startSanta.c;

    while(1){
        if(isRudolf){
            nr += rdx[dir];
            nc += rdy[dir];
        }else{
            nr += sdx[dir];
            nc += sdy[dir];
        }

        if(!isInRange(nr,nc)) break;
        if(maps[nr][nc]==0) break;
        candidate[cnt++]=maps[nr][nc];
    }

    // 연쇄적으로 밀려나는 애들

    for(int i=0;i<cnt;i++){
        int idx = candidate[i];
        Santa santa = santas[idx];

        int snr = santa.r;
        int snc = santa.c;

        if(isRudolf){
            snr += rdx[dir];
            snc += rdy[dir];
        }else{
            snr += sdx[dir];
            snc += sdy[dir];
        }

        if(!isInRange(snr,snc)){
            santas[idx].isDie = true;
        }

        santas[idx].r = snr;
        santas[idx].c = snc;
    }

}

void setMap(){
    for(int r=1;r<=N;r++){
        for(int c=1;c<=N;c++){
            maps[r][c]=0;
        }
    }
    for(int p=1;p<=P;p++){
        if(!santas[p].isDie){
            maps[santas[p].r][santas[p].c]=p;// 산타의 번호 기록
        }
    }
    maps[rudolf.r][rudolf.c]=RUDOLF;
}


void rudolfMove(int round){

    setMap();

    int nearSantaIdx = getNearSantaIndex();
    int rudolfDirection = getRudolfDirection(nearSantaIdx);
    
    if(rudolfDirection==-1) return;

    int nr,nc;
    nr = rudolf.r+rdx[rudolfDirection];
    nc = rudolf.c+rdy[rudolfDirection];

    if(!isInRange(nr,nc)) return;

    rudolf.r=nr;
    rudolf.c=nc;

    int snr,snc;

    // 루돌프가 움직여 충돌
    if(maps[nr][nc]!=0){
        int crashSantaIdx = maps[nr][nc];
        Santa crashSanta = santas[crashSantaIdx];

        snr = crashSanta.r + (rdx[rudolfDirection]*C);
        snc = crashSanta.c + (rdy[rudolfDirection]*C);
        
        // 게임판 밖이면 탈락
        if(!isInRange(snr,snc)){
            santas[crashSantaIdx].isDie = true;

        }else if(maps[snr][snc]!=0){
            // 밀려난 위치에 산타가 있는 경우 상호작용
            int interSantaIndex = maps[snr][snc];
            // 산타가 밀려나서 이동한 곳에 산타가 있으면 상호작용! -> 산타의 이동이기에 4방향으로 이동
            interaction(interSantaIndex,rudolfDirection,true);

        }
        santas[crashSantaIdx].r = snr;
        santas[crashSantaIdx].c = snc;

        santas[crashSantaIdx].stun = 2;

        santas[crashSantaIdx].score += C;
    }
}

void moveSanta(int santaIdx){
    setMap();

    Santa s = santas[santaIdx];
    int distance = getDistance(rudolf.r,rudolf.c,s.r,s.c);
    int direction = -1;
    int minDistance = INT_MAX;

    for(int i=0;i<4;i++){
        int nr,nc;
        nr = s.r+sdx[i];
        nc = s.c+sdy[i];

        if(!isInRange(nr,nc)) continue;
        
        int nextDistance = getDistance(rudolf.r,rudolf.c,nr,nc);

        if(distance<nextDistance) continue;

        if(maps[nr][nc]==RUDOLF){
            minDistance = 1;
            direction = i;
            break;
        }

        if(maps[nr][nc]!=0) continue;

        if(nextDistance<minDistance){
            minDistance = nextDistance;
            direction = i;
        }
    }

    // 움직일수 있는 칸 없다

    if(direction==-1){
        return;
    }

    santas[santaIdx].r = s.r+sdx[direction];
    santas[santaIdx].c = s.c+sdy[direction];

    // 루돌프와 충돌
    if(maps[santas[santaIdx].r][santas[santaIdx].c]==RUDOLF){
        santas[santaIdx].stun = 1;
        santas[santaIdx].score+=D;
        // 상 우 하 좌 0 1 2 3
        // 하 좌 상 우 2 3 0 1
        int changeDir[4]={2,3,0,1};
        int snr,snc;
        direction = changeDir[direction];
        snr = santas[santaIdx].r+(sdx[direction]*D);
        snc = santas[santaIdx].c+(sdy[direction]*D);
        if(!isInRange(snr,snc)){
            santas[santaIdx].isDie = true;
            return;
        }
        santas[santaIdx].r = snr;
        santas[santaIdx].c = snc;
        if(maps[snr][snc]!=0){
            int interSantaIdx = maps[snr][snc];
            // 산타와 충돌하면 안됨!!
            if(interSantaIdx!=santaIdx){
                interaction(interSantaIdx,direction,false);
            }
        }
    }
}

void allSantaMove(){
    for(int i=1;i<=P;i++){

        Santa s = santas[i];
        if(s.isDie) continue;

        if(s.stun!=0){
            santas[i].stun--; //여기서 기절은 1 감소시켜야함!
            continue;
        }

        moveSanta(i);
    }
}

bool isAllDie(){
    for(int i=1;i<=P;i++){
        if(!santas[i].isDie) return false;
    }
    return true;
}

void simulate(){
    int ans = 0;
    for(int i=0;i<M;i++){

        rudolfMove(i);
        allSantaMove();

        if(isAllDie()) break;
        for(int j=1;j<=P;j++){
            if(!santas[j].isDie){
                santas[j].score++;
            }
        }
    }

    for(int p=1;p<=P;p++){
        cout<<santas[p].score<<" ";
    }
    cout<<"\n";

}

void input(){
    cin>>N>>M>>P>>C>>D;
    cin>>Rr>>Rc;
    rudolf.r=Rr;
    rudolf.c = Rc;
    int idx,r,c;
    for(int i=1;i<=P;i++){
        cin>>idx>>r>>c;
        santas[idx].r=r;
        santas[idx].c=c;
        maps[r][c]=idx;
        santas[idx].idx=idx;
        santas[idx].isDie=false;
        santas[idx].stun = 0;
        santas[idx].score=0;
    }
}

int main(){
    input();
    simulate();

}