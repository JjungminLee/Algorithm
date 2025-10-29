#include<bits/stdc++.h>
using namespace std;
char arr[5][5];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int answer=0;


// v에 있는 좌표들이 인접했는지 판단해야함
// 좌표들을 bfs하면서 기존 v에 있는 좌표들과 일치하는지 판단해야함

bool bfs(vector<pair<int,int>>v){
    queue<pair<int,int>>q;
    bool visited[5][5]={false,};
    q.push(v[0]);
    visited[v[0].first][v[0].second]=true;
    int ans=1;
    bool selected[5][5]={false,};
    for(int i=0;i<v.size();i++){
        selected[v[i].first][v[i].second]=true;
    }

    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<5&&ny>=0&&ny<5){
                if(!visited[nx][ny]&&selected[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                    ans++;
                }
            }
        }
    }


    return ans==7;

}

void backTracking(int idx, vector<pair<int,int>>v,int sCount){
    if(v.size()==7){
        if(sCount>=4&&bfs(v)){
            answer++;
        }
        return;
    }
    for(int i=idx;i<25;i++){ // 1차원으로 쓰는게 더 효율적!
        int x = i/5;
        int y =i%5;
        v.push_back({x,y});
        backTracking(i+1,v,arr[x][y]=='S'?sCount+1:sCount);// idx+1이 아니라 i+1임
        v.pop_back();
    }

}
int main(){
    for(int i=0;i<5;i++){
        string str;
        cin>>str;
        for(int j=0;j<5;j++){
            arr[i][j]=str[j];
        }
    }
    vector<pair<int,int>>v;
    backTracking(0,v,0);
    cout<<answer<<endl;

}