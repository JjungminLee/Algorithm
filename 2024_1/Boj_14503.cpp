#include <bits/stdc++.h>
using namespace std;
// bfs를 통해
// 1.청소하는 함수
// 현재 칸이 청소되지 않았다면 현재 칸을 청소한다.
// 2. 상하좌우 도는 함수
// 3. 청소하지 않은 부분이 없을 때 실행할 함수
// 후진하고  -> 1번
// 후진 못하면 -> 멈추기
//4.  청소하지 않은곳이 있을 때 실행하는 함수
// 반시계방향으로 90도 회전
// 바라보는 방향 기준으로 청소되지 않으면 한칸 전진 -> 1번으로
/*
상 -> 좌
좌 -> 하
하 -> 우
우->상
*/
/*
0 -> 상
1-> 우
2->하
3-> 좌
*/
int N,M;
int r,c;
int d;
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
int visited[51][51];
int cnt=0;
void rotateDir(int x,int y,int d);
void cleanUp(int x,int y,int d);
void cleanUp(int x,int y,int d){
    if(x>=0&&x<N&&y>=0&&y<M){
        if(visited[x][y]==0){
            visited[x][y]=1;
            cnt++;
        }
    }
    rotateDir(x,y,d);

}
void rotateDir(int x,int y,int d){
    bool flag;
    for(int i=0;i<4;i++){
        int nx=x+dirX[i];
        int ny=y+dirY[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<M){
            if(visited[nx][ny]==0){
                flag=true;
            }
        }
    }
    // 청소되지 않은 빈칸이 있는 경우
    if(flag){
        if(d==0){
            d=3;
            // 상->좌
            if(visited[x][y-1]==0){
                cleanUp(x,y-1,d);
            }

        }else if(d==1){
            d=0;
             // 우->상
            if(visited[x-1][y]==0){
                cleanUp(x-1,y,d);
            }
            
        }else if(d==2){
            d=1;
             // 하->우
            if(visited[x][y+1]==0){
                cleanUp(x,y+1,d);
            }

        }else if(d==3){
            d=2;
              //좌->하
            if(visited[x+1][y]==0){
                cleanUp(x+1,y,d);
            }

        }

    }else{
        //상
        if(d==0){
            if(visited[x+1][y]==0){
                cleanUp(x+1,y,d);
            }else{
                return;
            }


        }
        //우
        else if(d==1){
            if(visited[x][y+1]==0){
                cleanUp(x,y+1,d);
            }else{
                return;
            }

        }//하
        else if(d==2){
            if(visited[x-1][y]==0){
                cleanUp(x-1,y,d);
            }else{
                return;
            }

        }//좌
        else if(d==3){
            if(visited[x][y-1]==0){
                cleanUp(x,y-1,d);
            }else{
                return;
            }

        }

    }
}

int main(){
    // 0이면 청소안한 빈칸 1이면 벽
    cin>>N>>M;
    cin>>r>>c>>d;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int num;
            cin>>num;
            if(num==1){
                //벽이면 -1
                visited[i][j]=-1;
                // 방문가능하면 0
                // 방문하면 1
            }
        }
    }
    cleanUp(r,c,d);
    cout<<cnt<<endl;

}