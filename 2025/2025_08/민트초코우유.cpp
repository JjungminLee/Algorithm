#include<bits/stdc++.h>

using namespace std;

#define MAX (50+5)
// milk랑 mint 헷갈릴수 있어서 TMINT로
#define TMINT_CHOCO_MILK (111)
#define TMINT_CHOCO (11)
#define TMINT_MILK (101)
#define CHOCO_MILK (110)
#define MILK (100)
#define CHOCO (10)
#define TMINT (1)

#define UP (0)
#define DOWN (1)
#define LEFT (2)
#define RIGHT (3)

int n,t;
char F[MAX][MAX];
int B[MAX][MAX];

struct STUDENT{
    int food; //신봉 음식
    int believe;
    bool isLeader;
    int defense; // 방어 했는지
    int row; // 좌표 , 추후 대표자 선정을 위함
    int col;
    
};

STUDENT student[MAX][MAX];
STUDENT candidates[MAX*MAX];
int ccnt;
STUDENT group[3+1][MAX*MAX];
int indexS[3+1];

struct RC{
    int r;
    int c;
};

bool visited[MAX][MAX];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};


void input(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>F[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>B[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            student[i][j].believe=B[i][j];
            student[i][j].isLeader=false;
            student[i][j].defense=0;
            student[i][j].row=i;
            student[i][j].col=j;

            if(F[i][j]=='T') student[i][j].food=TMINT;
            else if(F[i][j]=='C') student[i][j].food=CHOCO;
            else if(F[i][j]=='M') student[i][j].food = MILK;
        }
    }
}

// 디버깅도 함수로 만들어야 함

void morning(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            student[i][j].believe++;
        }
    }

}

bool isPriority(STUDENT a,STUDENT b){
    if(a.believe!=b.believe) return a.believe>b.believe;
    if(a.row!=b.row) return a.row<b.row;

    return a.col<b.col;
}

void bfs(int sx,int sy){

    queue<pair<int,int>> q;
    visited[sx][sy]=true;
    q.push({sx,sy});

    ccnt = 0;
    candidates[ccnt++] = student[sx][sy];

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n){
                if(!visited[nx][ny]){
                    if(student[cx][cy].food==student[nx][ny].food){
                        q.push({nx,ny});
                        visited[nx][ny] = true;
                        candidates[ccnt++] = student[nx][ny];
                    }
                }

            }
        }
    }

    STUDENT leader = {0};
    for(int i=0;i<ccnt;i++){
        if(isPriority(candidates[i],leader)){
            leader =  candidates[i];
        }
    }
    student[leader.row][leader.col].isLeader = true;
    student[leader.row][leader.col].believe += (ccnt-1);

    for(int i = 0;i<ccnt;i++){
        STUDENT c = candidates[i];
        if(c.row==leader.row &&c.col==leader.col) continue;

        student[c.row][c.col].believe--;
    }

}

void lunch(){

    // 점심마다 그룹, 대표자 선정하기에 초기화 필요
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visited[i][j]=false;
            student[i][j].isLeader = false;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visited[i][j]) continue;
            bfs(i,j);
        }
    }

}

int getGroupNumber(int food){
    if(food==TMINT_CHOCO_MILK) return 3;
    if(food==TMINT || food==CHOCO || food==MILK) return 1;
    return 2;

}

// 기존 음식을 덮어 씌우는게 핵심
// 비트 연산자로
int mixFood(int sFood,int nFood){

    return sFood | nFood;
}

void dinner(){
    // 대표를 그룹으로 분리 -> 단일, 이중, 삼중
    for(int i=1;i<=3;i++){
        indexS[i]=0;
    }

    // 그룹별 분리
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            STUDENT s = student[i][j];

            if(s.isLeader==false) continue;
            int groupNumber = getGroupNumber(s.food);

            group[groupNumber][indexS[groupNumber]++] =s;
        }
    }


    // 정렬
    for(int g=1;g<=3;g++){
        int gindexS = indexS[g];
        for(int i=0;i<gindexS-1;i++){
            for(int k=i+1;k<gindexS;k++){
                STUDENT a = group[g][i];
                STUDENT b = group[g][k];
                if(!isPriority(a,b)){
                    group[g][i]=b;
                    group[g][k]=a;
                }
            }
        }
    }

    //전파
    for(int g=1;g<=3;g++){
        int gindexS = indexS[g];
        for(int i=0;i<gindexS;i++){
            int gr,gc;
            gr = group[g][i].row;
            gc = group[g][i].col;
            //음식은 전파할때마다 갱신, 방어 상태는 전파 완료 후 갱신
            STUDENT spreader = student[gr][gc];

            // 방어 상태 대표자는 전파 안함
            if(spreader.defense!=0) continue;

            int sr,sc;
            sr = spreader.row;
            sc = spreader.col;

            student[sr][sc].believe=1;
            int x = spreader.believe-1;
            int dir = spreader.believe%4;

            while(1){
                int nr,nc;
                nr = sr+ dx[dir];
                nc = sc+dy[dir];
                if(nr>=1&&nr<=n&&nc>=1&&nc<=n&&x!=0){
                    STUDENT next = student[nr][nc];
                    if(next.food==spreader.food){
                        sr = nr;
                        sc = nc;
                        continue;
                    }

                    int y = next.believe;
                    student[next.row][next.col].defense=1;

                    if(x>y){
                        x -= (y+1);
                        if(x<0) x=0;
                        student[next.row][next.col].believe++;
                        student[next.row][next.col].food = spreader.food;
                    }else{
                        //전파 성공
                        student[next.row][next.col].believe+=x;
                        student[next.row][next.col].food = mixFood(spreader.food,next.food);

                        x = 0;
                        break;
                    }

                    sr = nr;
                    sc = nc;
                }else{
                    break;
                }
            }


        }
    }


    // 전부 다 전파하고 방어상태 갱신
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            student[i][j].defense = 0;
        }
    }




}

void printAnswer(){
    int sum[TMINT_CHOCO_MILK+1]={0,};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[student[i][j].food]+=student[i][j].believe;
        }
    }

    int outputindexS[7]
    ={TMINT_CHOCO_MILK,TMINT_CHOCO,TMINT_MILK,CHOCO_MILK,MILK,CHOCO,TMINT};

    for(int i=0;i<7;i++){
        cout<<sum[outputindexS[i]]<<" ";
    }
    cout<<"\n";

}

void simulate(){
    for(int i=0;i<t;i++){
        morning();
        lunch();
        dinner();
        printAnswer();
    }
}

int main(){
    input();
    simulate();

}