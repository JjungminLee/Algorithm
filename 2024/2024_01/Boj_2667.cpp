#include <bits/stdc++.h>

using namespace std;
char arr[26][26];
bool visits[26][26];
int N;
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
int ans = 0;
vector<int> ansVector;

void bfs(int x,int y){

    queue<pair<int,int>> q;
    q.push({x,y});
    visits[x][y]=true;
    int cnt = 1;
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int newX = curX+dirX[i];
            int newY = curY+dirY[i];
            if(newX>=0&&newX<N&&newY>=0&&newY<N){
                if(!visits[newX][newY]&&arr[newX][newY]=='1'){
                    cnt++;
                    q.push({newX,newY});
                    visits[newX][newY]=true;
                }
            }
        }
    }
    ansVector.push_back(cnt);
    ans++;
    

}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]=='1'&&!visits[i][j]){
                bfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    sort(ansVector.begin(),ansVector.end());
    for(int i=0;i<ansVector.size();i++){
        cout<<ansVector[i]<<endl;
    }

}