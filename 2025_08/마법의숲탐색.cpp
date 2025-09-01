#include<bits/stdc++.h>
using namespace std;

#define MAX (80)
#define MAX_K (1005)
#define BODY (1)
#define EXIT (3)
#define CENTER (2)

struct Gollom{
    int dir;
    int id;
    int r;
    int c;
};

struct Node{
    int r;
    int c;
};

int arr[MAX][MAX];
int R,C;
int k;
int gcnt=0;
// 북 동 남 서
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int answer;


bool checkDown(int r,int c){
    if(r==R+1) return false;
    int rr[3]={0};
    int cc[3]={0};
    rr[0]=r+1;
    rr[1]=r+2;
    rr[2]=r+1;
    cc[0]=c-1;
    cc[1]=c;
    cc[2]=c+1;
    for(int i=0;i<3;i++){
        if(arr[rr[i]][cc[i]]!=0) return false;
    }
    return true;
}

bool checkWest(int r,int c){
    if(c==2) return false;
    int rr[3]={0};
    int cc[3]={0};
    rr[0]=r-1;
    rr[1]=r;
    rr[2]=r+1;
    cc[0]=c-1;
    cc[1]=c-2;
    cc[2]=c-1;
    for(int i=0;i<3;i++){
        if(arr[rr[i]][cc[i]]!=0) return false;
    }
    // 문제 속 그림에서 서쪽으로 한번 이동 후 아래로 이동함
    return checkDown(r,c-1);
}

bool checkEast(int r,int c){
    if(c==C-1) return false;
    int rr[3]={0};
    int cc[3]={0};
    rr[0]=r-1;
    rr[1]=r;
    rr[2]=r+1;
    cc[0]=c+1;
    cc[1]=c+2;
    cc[2]=c+1;
    for(int i=0;i<3;i++){
        if(arr[rr[i]][cc[i]]!=0) return false;
    }
    
    return checkDown(r,c+1);

}

void printArr(){
    for(int i=0;i<=R+3;i++){
        for(int j=0;j<=C+3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// 가장 남쪽에 도달할때까지 -> R에 도달 못할수도 있음!
int bfs(Gollom g){
    bool visited[MAX][MAX]={0,};
    queue<Node>q;
    q.push({g.r,g.c});
    visited[g.r][g.c]=true;
    int maxNum =0 ;
    while(!q.empty()){
        
        int gr = q.front().r;
        int gc = q.front().c;
        int gid =arr[gr][gc]/10;
        int type = arr[gr][gc]%10;
        q.pop();
        maxNum = max(maxNum,gr);

        for(int i=0;i<4;i++){
            int nr = gr+dr[i];
            int nc = gc+dc[i];
            
            // 중심좌표 행 1부터 시작해서
            if(nr>=1&&nr<=(R+3)&&nc>=1&&nc<=C){
                int nid = arr[nr][nc]/10;
                int ntype = arr[nr][nc]%10;
                if(!visited[nr][nc]&&arr[nr][nc]!=0){
                    // 현재 출구가 아니고 id가 다르면 
                    // body여도 이동하다가 id다른지점에서 끝날거고
                    // Exit이면 또 다른 골렘으로 타고타고 이동 가능할거임
                    if(type!=EXIT&&gid!=nid) continue;
                    visited[nr][nc]=true;
                    q.push({nr,nc});

                }
            }
        }

    }
    return maxNum-2;
}
void setGolom(Gollom g){
    int gr = g.r;
    int gc = g.c;
    int gid = g.id;
    int dir = g.dir;
    arr[gr][gc]=gid+CENTER;
    for(int i=0;i<4;i++){
        int nr = gr+dr[i];
        int nc = gc+dc[i];
        arr[nr][nc] = gid+BODY;
    }
    arr[gr+dr[dir]][gc+dc[dir]] = gid+EXIT;
}


void clearArr(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            arr[i][j]=0;
        }
    }

}
int simulate(Gollom g){

    int cnt = 0;

    while(1){
        if(checkDown(g.r,g.c)){
                g.r+=1;
        }else if(checkWest(g.r,g.c)){
               
                g.r+=1;
                g.c-=1;
                g.dir = (g.dir-1+4)%4; // 4더하는거 중요!
        }else if(checkEast(g.r,g.c)){
               
                g.c+=1;
                g.r+=1;
                g.dir = (g.dir+1)%4;
        }else{
                break;
        }
    }

    if(g.r<=3){ // 골렘의 몸 전체가 arr에 못들어옴
        clearArr();
        return 0;
    }

    setGolom(g);
    return bfs(g);

}

void input(){
    cin>>R>>C>>k;
    for(int i=1;i<=k;i++){
        int c,d;
        cin>>c>>d;
        Gollom g ={0,};
        g.dir=d;
        g.id=10*i;
        g.r=1; // 0부터 시작하면 겹쳐질수 있음!!
        g.c=c;
        answer +=simulate(g);
    }
    cout<<answer<<"\n";
}

int main(){
    input();
}