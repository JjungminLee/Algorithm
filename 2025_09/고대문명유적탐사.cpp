#include<bits/stdc++.h>
using namespace std;

#define MAX (15)
#define M_MAX (350)

int K,M;
int arr[MAX][MAX];
int walls[M_MAX];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int wcnt=0;

void copyArr(int src[MAX][MAX],int dest[MAX][MAX]){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            src[i][j] = dest[i][j];
        }
    }
}

void rotate(int map[MAX][MAX],int sr,int sc){

    int temp[MAX][MAX]={0,};
    copyArr(temp,map);

    // 3*3 을 선택하기
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            map[r+sr][c+sc] = temp[3-1-c+sr][r+sc];
        }

    }

}

int bfsCount(int map[MAX][MAX],bool visited[MAX][MAX],int num,int sx,int sy){
    queue<pair<int,int>>q;
    visited[sx][sy]=true;
    q.push({sx,sy});

    int sum = 1;

    while(!q.empty()){
        auto cur = q.front();
        int cx = cur.first;
        int cy = cur.second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0&&nx<5&&ny>=0&&ny<5){
                if(!visited[nx][ny]&&map[nx][ny]==num){
                    visited[nx][ny]=true;
                    sum++;
                    q.push({nx,ny});
                }
            }
        }
    }
    return sum;

}

// 연결된 것만 삭제
void deleteBfs(int map[MAX][MAX],int x,int y){
    int num = map[x][y];
    queue<pair<int,int>>q;
    bool visited[MAX][MAX]={0,};
    q.push({x,y});
    map[x][y]=0;
    visited[x][y]=true;

     while(!q.empty()){
        auto cur=q.front(); 
        q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int d=0; d<4; d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(0<=nx && nx<5 && 0<=ny && ny<5){
                if(!visited[nx][ny] && map[nx][ny]==num){
                    visited[nx][ny]=true;
                    map[nx][ny]=0;           
                    q.push({nx,ny});
                }
            }
        }
    }

}

int getItem(int map[MAX][MAX]){
    // 3개이상 연결된
    bool visited[MAX][MAX]={false,};
    int sum = 0;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(!visited[i][j]&&map[i][j]!=0){ // 빈칸이여도 안됨
                int count = bfsCount(map,visited,map[i][j],i,j);
                if(count<3) continue;
                sum+=count;
                deleteBfs(map,i,j); 
            }
        }
    }
    return sum;
}

void setItem(int map[MAX][MAX]){
   for(int col=0;col<5;col++){
        for(int row=4;row>=0;row--){
            if(map[row][col]==0&&wcnt<M){ // 조건이 중요
                map[row][col]=walls[wcnt++];
            }
        }
    }

}


int simulate(){
    int sum = 0;
    int maxMap[MAX][MAX]={0,};
    int maxItemCount = 0;

    // 회전 각도 작고
    for(int rot=1;rot<=3;rot++){
        // 열이 작고
        for(int c=0;c<3;c++){
            // 행이 작은 순
            for(int r=0;r<3;r++){
                int tMap[MAX][MAX] = {0,};
                copyArr(tMap,arr);
                for(int rotCnt=0;rotCnt<rot;rotCnt++){
                    rotate(tMap,r,c);
                }
                int itemCnt = getItem(tMap);

                if(maxItemCount<itemCnt){
                    maxItemCount = itemCnt;
                    copyArr(maxMap,tMap);
                }

            }

        }
    
    }
    // 3개이상 조각이 연결되지 않아 유물이 될 수 없으면 리턴
    if(maxItemCount==0) return 0;
    sum += maxItemCount;
    while(true){
        setItem(maxMap);
        int itemCnt = getItem(maxMap);
        if(itemCnt==0) break;
        sum+=itemCnt;
    }
    copyArr(arr,maxMap);

    return sum;

}

void input(){
    cin>>K>>M;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<M;i++){
        cin>>walls[i];
    }

}

int main(){
    input();
    for(int i=0;i<K;i++){
        int res = simulate();
        if(res==0) break;
        cout<<res<<" ";
    }
    cout<<endl;
    
    return 0;

}