#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[52][52];
string s;
int maxH=INT_MIN;
int minH=INT_MAX;
int ans;
bool visited[51][51];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
//외부에서 내부로 물이 흘러들어갈 수 있는 모든 경로 탐색
void bfs(int h){
    queue<pair<int,int>>q;
    q.push({0,0});
    arr[0][0]=h;
    memset(visited,0,sizeof(visited));
    visited[0][0]=true;
    while(!q.empty()){
        int x= q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            // 여기가 제일 어려움!
            // 외부 경계 떄문에 실제로는 1부터 n까지 입력됐지만 0부터 n+1까지 검사
            if(nx>=0&&nx<=n+1&&ny>=0&&ny<=m+1){
                if(arr[nx][ny]<h){
                    arr[nx][ny]=h;
                    q.push({nx,ny});
                }
            }
        }
    }

}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            arr[i][j]=ch-'0';
            if(maxH<arr[i][j]){
                maxH=arr[i][j];
            }
            if(minH>arr[i][j]){
                minH=arr[i][j];
            }
        }
    }

    for(int i=1;i<=maxH;i++){
        bfs(i);
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                if(arr[j][k]<i){
                    // 물 추가시키기
                    arr[j][k]+=1;
                    ans++;
                }
            }
        }
    }


    cout<<ans<<endl;
    
}