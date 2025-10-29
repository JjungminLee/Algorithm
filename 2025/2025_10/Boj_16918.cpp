#include<bits/stdc++.h>
using namespace std;
int R,C,N;
char maps[205][205];
int bombs[205][205];// 폭탄이 설치된 시간

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

void installBomb(int curTime){
    for(int i=0;i<205;i++){
        for(int j=0;j<205;j++){
            if(maps[i][j]=='.'){
                maps[i][j]='O';
                bombs[i][j]=curTime;
            }
        }
    }

}

void explodeBomb(int curTime){
    char tmp[205][205];
    for(int i=0;i<205;i++){
        for(int j=0;j<205;j++){
            tmp[i][j]=maps[i][j];
        }
    }
    
    int explodeTime = curTime-3;
    for(int i=0;i<205;i++){
        for(int j=0;j<205;j++){
            if(bombs[i][j]==explodeTime){
                    // 상하좌우
                    tmp[i][j]='.';
                    for(int k=0;k<4;k++){
                        int nr = i+dr[k];
                        int nc = j+dc[k];
                        if(nr>=0&&nr<R&&nc>=0&&nc<C){
                            tmp[nr][nc]='.';
                        }
                    }
            }
        }
    }

    for(int i=0;i<205;i++){
        for(int j=0;j<205;j++){
            maps[i][j]=tmp[i][j];
        }
    }

}

void simulate(){

}

int main(){
    cin>>R>>C>>N;
    for(int i=0;i<205;i++){
        for(int j=0;j<205;j++){
            bombs[i][j]=-1;
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>maps[i][j];
            if(maps[i][j]=='O'){
                bombs[i][j]=0;
            }
        }
    }
    
    int time =0;

    while(time<N){
        time++;
        if(time==1) continue;
        if(time%2==0) installBomb(time);
        else explodeBomb(time);
    }

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<maps[i][j];
        }
        cout<<"\n";
    }

}