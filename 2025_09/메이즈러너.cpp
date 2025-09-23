#include <bits/stdc++.h>

using namespace std;

#define MAX 15

int M,N;
int K;
int maps[MAX][MAX];
int er,ec;

struct Node{
    int r;
    int c;
};

Node members[MAX];

void input(){
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>maps[i][j];
        }
    }

    for(int i=0;i<M;i++){
        int r,c;
        cin>>r>>c;
        members[i]={r,c};
    }
    cin>>er>>ec;

}

void setMaps(){
    // 현위치에서 출구까지 최단거리 구하기
    // 출구까지 다익스트라
}

void moving(){

}

void rotating(){

}

void simulate(){

    while(K--){
        moving();
        rotating();
    }
}




int main(){
    input();
    simulate();
    

}