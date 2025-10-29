#include<bits/stdc++.h>

using namespace std;

#define MAX (55)

int n;
int q;
int r1,c1;
int r2,c2;

char stones [MAX][MAX];
int dist[6][MAX][MAX];
bool isMove[MAX][MAX][MAX][MAX]; // 점프하다 이동 경로중에 #가 있어도 이동 불가
// x,y=>nx,ny까지 이동가능한지 판별
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct Frog{
    int time;
    int row;
    int col;
    int jump;
};

struct Cmp{
    bool operator()(const Frog&a,const Frog&b)const{
        return a.time>b.time;

    }
};

priority_queue<Frog,vector<Frog>,Cmp> pq;

void input(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>stones[i][j];
        }
    }
}

void resetDist(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[i][j][k]=1e9;
            }
        }
    }
}

void resetIsMove(){
    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            for(int c=1;c<=n;c++){
                for(int d=1;d<=n;d++){
                    isMove[a][b][c][d]=false;
                }
            }
        }
    }

    for(int a=1;a<=n;a++){
        for(int b=1;b<=n;b++){
            if(stones[a][b]!='.') continue;
            for(int c=0;c<4;c++){
                for(int d=1;d<=5;d++){
                    int nx,ny;
                    nx = a+(dx[c]*d);
                    ny = b+(dy[c]*d);
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                        if(stones[nx][ny]=='#') break;
                        if(stones[nx][ny]=='S') continue;
                        isMove[a][b][nx][ny]= true;
                    }
                }
            }
        }
    }
}
int getCost(int start,int end){
    // 점프력 증가후 점프력을 k라고 할떄 k^2만큼의 시간이 소요
    int cost = 0;
    for(int k=start+1;k<=end;k++){
        cost += k*k;
    }
    return cost;
}

void increase(Frog frog){
    for(int i=frog.jump+1;i<=5;i++){ // 점프력 증가
        for(int j=0;j<4;j++){ // 이동
            int nx = frog.row+(dx[j]*i);
            int ny = frog.col+(dy[j]*i);
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                if(isMove[frog.row][frog.col][nx][ny]){
                    int cost = getCost(frog.jump,i);
                    if(dist[i][nx][ny]>frog.time+cost+1){
                        dist[i][nx][ny]=frog.time+cost+1;
                        pq.push({frog.time+cost+1,nx,ny,i});
                    }
                }
            }
        }
    }
}

void decrease(Frog frog){

   for(int i=1;i<=frog.jump-1;i++){ // 점프력 감소
        for(int j=0;j<4;j++){ // 이동
            int nx = frog.row+(dx[j]*i);
            int ny = frog.col+(dy[j]*i);
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                if(isMove[frog.row][frog.col][nx][ny]){
                    // 점프 감소 소요 시간, 점프 감소 후 이동 소요시간
                    if(dist[i][nx][ny]>frog.time+1+1){
                        dist[i][nx][ny]=frog.time+1+1;
                        pq.push({frog.time+1+1,nx,ny,i});
                    }
                }
            }
        }
    }

}

void jump(Frog frog){

    int curx = frog.row;
    int cury = frog.col;
    for(int i=0;i<4;i++){
        int nx = curx+dx[i]*frog.jump;
        int ny = cury+dy[i]*frog.jump;
        if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
            if(isMove[frog.row][frog.col][nx][ny]){
                if(dist[frog.jump][nx][ny]>frog.time+1){
                    dist[frog.jump][nx][ny]=frog.time+1;
                    pq.push({dist[frog.jump][nx][ny],nx,ny,frog.jump});
                }
            }
        }
    }

}

void dijkstra(){

    resetDist();
    pq = priority_queue<Frog,vector<Frog>,Cmp>();
    pq.push({0,r1,c1,1});
    dist[1][r1][c1] = 0;

    while(!pq.empty()){
        Frog frog = pq.top();
        pq.pop();
        // 점프
        jump(frog);
        // 점프 증가 후 이동
        increase(frog);
        // 점프 감소 후 이동
        decrease(frog);
        
    }

}



void simulate(){
    cin>>q;
    while(q--){
        cin>>r1>>c1>>r2>>c2;
        dijkstra();
        
        int ans = 1e9;
        for(int i=1;i<=5;i++){
            ans = min(ans,dist[i][r2][c2]);
        }
        if(ans==1e9){
            cout<<-1<<'\n';
        }else{
            cout<<ans<<'\n';
        }
        
    }

}

int main(){

    input();
    resetIsMove();
    simulate();

}