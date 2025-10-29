#include<bits/stdc++.h>

using namespace std;

#define MAX (20000+10000+500)
#define INF (1000000000)

#define INIT (100)
#define CREATE (200)
#define REMOVE (300)
#define FIND (400)

int Q;
int N;

int house[MAX];
bool isBroken[MAX];
int hcnt=0;


void input(){
    cin>>N;
    hcnt=1;
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        house[hcnt++]=x;
    }

    for(int i=0;i<MAX;i++){
        isBroken[i]=false;
    }

}

void createAntHouse(int p){
    house[hcnt] = p;
    isBroken[hcnt]=false;
    hcnt++;

}

void removeAntHouse(int q){
    isBroken[q] = true;

}

void binarySearch(int r){

    int left = 0;
    int right = INF;
    int ans = 0;
    
    while(left<=right){
        int start=-1;
        int prevPos =-1;
        int cnt = 0;
        // 시간 동안 몇마리의 개미가 필요한지
        int mid = (left+right)/2;


        // 철거가 되지 않은 지점을 먼저 정하기!
        for(int i=1;i<hcnt;i++){
            if(!isBroken[i]){
                start = i;
                break;
            }
        }

        if(start==-1){
            ans=0;
            break;
        }

        prevPos = house[start];
        cnt = 1;

        // i번부터 hcnt번까지 현 위치에서 T초안에 갈수 있는 곳들 다 고르기!
        // 누적할 필요가 없음
        // start에서 hcnt-1까지 가는 시간을 구하면 그게 모든 집 정찰하는 시간이 됨
        // 대신 철거된 집을 판별해야 하기에 순회하는 것!
        for(int i=start+1;i<hcnt;i++){
            if(isBroken[i]) continue;
            int curPos = house[i];
            // curPos-prevPos>mid이면 더 많은 거리 걸어야 해서 추가로 개미 필요
            if(curPos-prevPos>mid){
                prevPos = curPos;
                cnt++;

            }
        }

        if(cnt<=r){
            ans = mid;
            right = mid-1;

        }else{
            left = mid+1;
        }
    }
    cout<<ans<<"\n";

}

void simulate(){

}
int main(){
    cin>>Q;
    for(int i=0;i<Q;i++){
        int cmd;
        cin>>cmd;
        if(cmd==INIT) input();
        else if(cmd==CREATE){
            int p;
            cin>>p;
            createAntHouse(p);
        }else if(cmd==REMOVE){
            int q;
            cin>>q;
            removeAntHouse(q);
        }else if(cmd==FIND){
            int r;
            cin>>r;
            binarySearch(r);
        }

    }
}