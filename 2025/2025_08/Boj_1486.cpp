#include<bits/stdc++.h>
using namespace std;
int n,m;
int t;
long long d;
int arr[26][26];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct Node{
    long long time;
    int x,y;
};

int go[26][26]; // 갈 때 시간
int back[26][26]; // 올 때 시간


int getHeight(char c){
    if('A'<=c&&c<='Z'){
        return c-'A';
    }
    if('a'<=c&&c<='z'){
        return c-'a'+26;
    }
}


void dijkstra(int sx,int sy,int dist[26][26],bool isDown){
    priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<>> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=1e9;
        }
    }
    pq.push({0,sx,sy});
    dist[sx][sy]=0;

    while(!pq.empty()){
        auto [curTime,curx,cury] = pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&abs(arr[nx][ny]-arr[curx][cury])<=t){
                int diff = arr[nx][ny] - arr[curx][cury];
                int cost;
                if(isDown){
                    cost = diff>=0?1:diff*diff;
                }else{
                    cost = diff>0?diff*diff:1;
                }
                int newTime = curTime + cost;
                if(dist[nx][ny]>newTime){
                    dist[nx][ny]=newTime;
                    pq.push({newTime,nx,ny});
                }
            }
        }
    }
}

int main(){
    cin>>n>>m>>t>>d;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            arr[i][j]=getHeight(str[j]);
        }
    }
    dijkstra(0,0,go,true);

    dijkstra(0,0,back,false);

    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(go[i][j]+back[i][j]<=d){
                result=max(result,arr[i][j]);

            }
        }
    }
    cout<<result<<endl;

}