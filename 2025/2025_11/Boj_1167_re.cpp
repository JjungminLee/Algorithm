#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>adj[100005];
int v;
int farNode;
int maxDist;

void dfs(int cur,int prev,int dist){
    if(dist>maxDist){
        maxDist=dist;
        farNode = cur;
    }
    for(auto[next,w]:adj[cur]){
        if(next==prev) continue;
        dfs(next,cur,dist+w);
    }
}

int main(){
    cin>>v;
    for(int i=0;i<v;i++){
        int node;
        cin>>node;
        while(1){
            int nextNode;
            cin>>nextNode;
            if(nextNode==-1) break;
            int nextDist;
            cin>>nextDist;
            adj[node].push_back({nextNode,nextDist});
        }
    }
    dfs(1,-1,0);
    int a = farNode;
    maxDist = 0;
    dfs(a,-1,0);

    cout<<maxDist<<"\n";
}