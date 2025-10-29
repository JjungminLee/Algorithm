#include<bits/stdc++.h>
using namespace std;

int n,m,t;
long long d;
int go[26][26];//등산 시간
int down[26][26];
int arr[26][26];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int getHeight(char c){
    if('A'<=c&&c<='Z'){
        return c-'A';
    }
    if('a'<=c&&c<='z'){
        return c-'a'+26;
    }
}

void dijkstra(int sx,int sy,int dist[26][26],bool isDown){
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            dist[i][j]=1e9;
        }
    }
    priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<>>pq;
    pq.push({0,sx,sy});
    dist[sx][sy]=0;
    
    while(!pq.empty()){
        auto[curTime,curx,cury]=pq.top();
        pq.pop();

        for(int i=0;i<4;i++){{
            int nx = curx+dx[i];
            int ny = cury+dy[i];
            
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&abs(arr[nx][ny]-arr[curx][cury])<=t){
                int diff = arr[nx][ny]-arr[curx][cury];
                int cost = 0;
                if(isDown){ // 하산할때는 높은 방향으로 가면 1만큼 걸림 
                    cost= diff>=0?1:diff*diff;
                }else{
                    cost = diff>0?diff*diff:1;
                }
                int newTime = curTime+cost;
                if(dist[nx][ny]>newTime){
                    dist[nx][ny]=newTime;
                    pq.push({newTime,nx,ny});
                }
            }
           
        }}

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
    int maxNum=0;
    dijkstra(0,0,go,true);
    dijkstra(0,0,down,false);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(go[i][j]+down[i][j]<=d){
                maxNum=max(maxNum,arr[i][j]);
            }
        }
    }
    cout<<maxNum<<endl;
    

}