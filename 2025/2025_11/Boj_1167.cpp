#include<bits/stdc++.h>

using namespace std;

int v;
vector<pair<int,int>>adj[100005];
int farNode;
int maxDist;

void dfs(int cur,int prev,int dist){
    if(dist>maxDist){
        maxDist = dist;
        farNode = cur;
    }
    
    for(auto[next, w]:adj[cur]){
    if(next==prev) continue;
    dfs(next,cur,dist+w);
   }
}

int main(){
    cin>>v;
    for(int i=0;i<v;i++){ 
        int curNode;
        cin>>curNode;

        int nextNode;
        while(1){
            cin>>nextNode;
            if(nextNode==-1) break;
            int nextNodeDist;
            cin>>nextNodeDist;
            adj[curNode].push_back({nextNode,nextNodeDist});

        }
    }

    dfs(1,-1,0);
    int a = farNode;
    maxDist = 0;
    dfs(a,-1,0);
    int diameter = maxDist;
    
    cout<<diameter<<"\n";

}