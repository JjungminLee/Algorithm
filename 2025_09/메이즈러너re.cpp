#include<bits/stdc++.h>

using namespace std;
#define MAX (15)
#define PLAYER_NUMBER (10)
#define DESTINATION (-1)

#define UP (0)
#define RIGHT (1)
#define DOWN (2)
#define LEFT (3)

int T;
int N,M,K;

int MAP[MAX][MAX];

struct RCE{
    int r;
    int c;
    bool escape; // 얘도 관리했어야
};

RCE player[MAX];
RCE destination;

struct RCS{
    int r;
    int c;
    int size;
};

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

void input(){
    cin>>N>>M>>K;
    for(int r=1;r<=N;r++){
        for(int c=1;c<=N;c++){
            cin>>MAP[r][c];
        }

    }
    for(int i=0;i<M;i++){
        cin>>player[i].r>>player[i].c;
        player[i].escape=false;
    }
    cin>>destination.r>>destination.c;


}

void copyMap(int copy[MAX][MAX], int original[MAX][MAX])
{
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			copy[r][c] = original[r][c];
}

int checkRow(RCE player){
    int dr = destination.r;
    int pr = player.r;
    return dr-pr;
}

int checkCol(RCE player){
    int dc = destination.c;
    int pc = player.c;
    return dc-pc;
}

int move(){
    int step=0;
    for(int m=0;m<M;m++){
        if(player[m].escape) continue;
        int nextR[4]={0};
        int nextC[4]={0};

        for(int i=0;i<4;i++){
            nextR[i]=player[m].r+dr[i];
            nextC[i]=player[m].c+dc[i];
        }
        int upDown = checkRow(player[m]);//출구가 참가자의 위or아래인지
        int leftRight = checkCol(player[m]);

        int direction = -1;

        // 항상 출구를 향해 움직이기에 격자 밖 검사 필요 x
        if(upDown<0&&MAP[nextR[UP]][nextC[UP]]==0) direction = UP;
        else if(upDown>0&&MAP[nextR[DOWN]][nextC[DOWN]]==0) direction=DOWN;
        else if(leftRight<0&&MAP[nextR[LEFT]][nextC[LEFT]]==0) direction=LEFT;
        else if(leftRight>0&&MAP[nextR[RIGHT]][nextC[RIGHT]]==0) direction=RIGHT;
        
        if(direction==-1) continue;

        player[m].r = player[m].r+dr[direction];
        player[m].c = player[m].c+dc[direction];

        if(player[m].r==destination.r&&player[m].c==destination.c){
            player[m].escape=true;
        }
       
        step++;
    }

    return step;
}

bool check(){
    for(int i=0;i<M;i++){
        if(!player[i].escape) return false;
    }
    return true;

}

bool rotateCheck(int map[MAX][MAX],int sr,int sc,int size){

    bool destinationCheck= false;
    bool playerCheck =false;

    for(int r=sr;r<sr+size;r++){
        for(int c=sc;c<sc+size;c++){
            if(map[r][c]>=PLAYER_NUMBER) playerCheck=true;
            else if(map[r][c]==DESTINATION) destinationCheck =true;
        }
    }
    return playerCheck&&destinationCheck;

}

RCS getSquareInfo(){
    RCS ret = {0};
    // 정사각형의 사이즈
    for(int size=2;size<=N;size++){
        for(int r=1;r<=N-size+1;r++){
            for(int c=1;c<=N-size+1;c++){
                int tmpMAP[MAX][MAX]={0,};

                for(int m=0;m<M;m++){
                    if(player[m].escape) continue;
                    tmpMAP[player[m].r][player[m].c]=m+PLAYER_NUMBER;
                }

                tmpMAP[destination.r][destination.c]=DESTINATION;

                //사각형 내부에 출구와 참가자?
                if(rotateCheck(tmpMAP,r,c,size)){
                    ret.r=r;
                    ret.c=c;
                    ret.size=size;
                    return ret;
                }
            }

        }
    }
    return ret;
}

void rotate(int map[MAX][MAX],int sr,int sc,int size){

    int tmpMAP[MAX][MAX]={0};
    for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
            tmpMAP[r][c]=map[sr+r][sc+c];
        }
    }
    for(int r=0;r<size;r++){
        for(int c=0;c<size;c++){
            map[sr+r][sc+c]=tmpMAP[size-1-c][r];
        }
    }
}
RCE rotateRC(RCE rce, RCS squareInfo){
    RCE ret = {0};
    int tmpMAP[MAX][MAX]={0,};
    tmpMAP[rce.r][rce.c]=1;

    rotate(tmpMAP,squareInfo.r,squareInfo.c,squareInfo.size);

    for(int r=1;r<=N;r++){
        for(int c=1;c<=N;c++){
            if(tmpMAP[r][c]==1){
                ret.r=r;
                ret.c=c;
                return ret;
            }
        }
    }
    return ret;
}

void durabilityDown(RCS squareInfo){
    int sr = squareInfo.r;
    int er = squareInfo.r+squareInfo.size;
    int sc = squareInfo.c;
    int ec = squareInfo.c+squareInfo.size;

    for(int r=1;r<=N;r++){
        for(int c=1;c<=N;c++){
            if(MAP[r][c]==0) continue;
            if(sr<=r&&r<er&&sc<=c&&c<ec){
                MAP[r][c]--;
            }
        }
    }
}
void rotateMaze(){
    RCS squareInfo = getSquareInfo();
    // map 회전 (벽 회전)
    rotate(MAP,squareInfo.r,squareInfo.c,squareInfo.size);

    // 도착지 회전
    destination = rotateRC(destination,squareInfo);

    for(int m=0;m<M;m++){
        if(player[m].escape) continue;
        // 플레이어들 위치 회전
        player[m]=rotateRC(player[m],squareInfo);
    }

    durabilityDown(squareInfo);

}

void simulate(){
    int sum=0;
    for(int k=0;k<K;k++){
        int step = move();
        sum+=step;
        if(check()){
            break;
        }
        rotateMaze();
    }
    cout<<sum<<"\n";
    cout<<destination.r<<" "<<destination.c<<"\n";

}

int main(){
    input();
    simulate();

}