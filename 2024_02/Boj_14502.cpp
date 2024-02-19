#include <bits/stdc++.h>

using namespace std;

int N,M;
int arr[9][9];
bool visits[9][9];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs(){

}

// 맵 전체를 돌며 빈칸이 나올 시, 해당 빈칸은 벽으로 바꾼 뒤, 2개씩 선택하는 조합 함수로 이동 
void dfs(int x,int y,int depth){
    if(depth==3){
        bfs();
        return;
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==0&&!visits[i][j]){

            }
        }
    }

}