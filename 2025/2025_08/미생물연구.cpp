#include <bits/stdc++.h>
using namespace std;

#define MAX (20)
#define MAX_Q (50+5)

struct MICRO{
    int id;
    int minR;
    int minC;
    int maxR;
    int maxC;
    int size;
};

struct Cmp{
    bool operator()(const MICRO&a,const MICRO&b)const{
        return a.size>b.size;

    }
};

int n,q;
int germs[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
MICRO micros[MAX_Q];
bool dead[MAX_Q]; 
int mcnt;



void input(){
    cin>>n>>q;
}


void addGerm(int r1,int c1,int r2,int c2,int idx){

    // 0부터 시작이라 r2에 등호 안붙음
    for(int i=r1;i<r2;i++){
        for(int j=c1;j<c2;j++){
            germs[i][j]=idx;
        }
    }
            
}

MICRO bfs(int sx,int sy){

    visited[sx][sy]=true;
    queue<pair<int,int>>q;
    q.push({sx,sy});
    int minR = sx, minC = sy;
    int maxR = sx, maxC = sy;
    int cnt = 0;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        cnt++;

        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n){
                if(!visited[nx][ny]&&germs[nx][ny]==germs[cx][cy]){
                    q.push({nx,ny});
                    minR = min(minR,nx);
                    maxR = max(maxR,nx);
                    minC = min(minC,ny);
                    maxC = max(maxC,ny);
                    visited[nx][ny]=true;
                }
            }
        }
    }

    MICRO ret ={0};
    ret.id = germs[sx][sy];
    ret.minR = minR;
    ret.maxR = maxR;
    ret.minC = minC;
    ret.maxC = maxC;
    ret.size = cnt;

    return ret;
}

void findLiveGerm(){
    mcnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }

    }

    bool checks[MAX_Q]={false};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int idx = germs[i][j];
            if(idx==0 || dead[idx] || visited[i][j]) continue;
            MICRO m = bfs(i,j);

            // ? checks는 뭐하는애? -> 두번 발견되면 죽음
            if(checks[m.id]){
                dead[m.id]=true;
                continue;
            }

            checks[m.id]=true;
            micros[mcnt++]=m;

        }

    }

    // 죽은 미생물 거르기
    int tcnt = mcnt;
    mcnt = 0;
    for(int i=0;i<tcnt;i++){
        if(dead[micros[i].id]) continue;
        micros[mcnt++]=micros[i];
    }

}

bool isPriority(MICRO a,MICRO b){
   if(a.size==b.size){
    return a.id<b.id;
   }
   return a.size>b.size;
}

void sort(){

    for(int i=0;i<mcnt-1;i++){
        for(int k=i+1;k<mcnt;k++){
            if(!isPriority(micros[i],micros[k])){
                MICRO tmp = micros[i];
                micros[i] = micros[k];
                micros[k] = tmp;
            }
        }

    }

}

bool checkMove(int newGerms[MAX][MAX],MICRO m, int r,int c){
    int sr = m.minR;
    int sc = m.minC;
    int er = m.maxR;
    int ec = m.maxC;

    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            // ? 왜 비어있을때 무시함?
            if(germs[i][j]!=m.id) continue;
            int nr = r-sr+i;
            int nc = c-sc+j;
            //격자밖
            if(nr>=n||nc>=n||nr<0||nc<0) return false;
            if(newGerms[nr][nc]) return false;
        }
    }

    return true;
}

void moves(int newGerms[MAX][MAX],MICRO m, int r,int c){
    int sr = m.minR;
    int sc = m.minC;
    int er = m.maxR;
    int ec = m.maxC;

    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){

            //? 왜 germs[i][j]==0인걸 알아야함?
            if(germs[i][j]!=m.id) continue;
            int nr = r-sr+i;
            int nc = c-sc+j;
            
            newGerms[nr][nc] =  m.id;
        }
    }
}

void moveMicro(int newGerms[MAX][MAX],MICRO m){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(checkMove(newGerms,m,i,j)){
                moves(newGerms,m,i,j);
                return;
            }
        }
    }
}

void moveAll(){
    int newGerms[MAX][MAX]={0,};
    for(int i=0;i<mcnt;i++){
        moveMicro(newGerms,micros[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            germs[i][j] = newGerms[i][j];
        }
    }

}

void moveGerm(){
    findLiveGerm();
    sort();
    moveAll();
}

int getSize(int id){
    for(int i=0;i<mcnt;i++){
        if(micros[i].id==id) return micros[i].size;
    }
    return -1;
}

void printGerm(int maxId){
    // 인접성 -> 예술성 문제 떠올리기
    bool company[MAX_Q][MAX_Q]={false,};
    int score=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(germs[i][j]==0) continue;
            for(int k=0;k<4;k++){
                int nr,nc;

                nr = i+dx[k];
                nc = j+dy[k];
                if(nr<0||nc<0||nr>=n||nc>=n) continue;

                int id1 = germs[i][j];
                int id2 = germs[nr][nc];

                if(id1==id2 ||id2==0) continue;
                company[id1][id2]=true;
                company[id2][id1]=true;
            }
        }
    }

    for(int i=1;i<=maxId-1;i++){
        for(int k=i+1;k<=maxId;k++){
            if(company[i][k]){
                int size1=getSize(i);
                int size2 = getSize(k);
                score +=(size1*size2);
            }
        }
    }

    cout<<score<<"\n";
  
}

void simulate(){
    int r1,c1,r2,c2;
    for(int i=1;i<=q;i++){
        cin>>r1>>c1>>r2>>c2;
        addGerm(r1,c1,r2,c2,i);
        moveGerm();
        printGerm(i);
    }
}

int main(){
    input();
    simulate();
}

