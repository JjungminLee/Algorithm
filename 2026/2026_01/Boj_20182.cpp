#include<bits/stdc++.h>

using namespace std;

int n,m,a,b,c;
int MAX = 100005;

vector<pair<int,int>>v[100005];
int dist[100005];


int main(){
    cin>>n>>m>>a>>b>>c;
    for(int i=0;i<MAX;i++){
        dist[i]=1e9;
    }
    for(int i=0;i<m;i++){
        int s,e,cnt;
        cin>>s>>e>>cnt;
        v[s].push_back({e,cnt});
        v[e].push_back({s,cnt});
    }

    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    dist[a]=0;
    pq.push({a,0});

    int ans=-1;

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        if(node.first==b){
            ans = node.second;
            break;
        }
        for(auto next:v[node.first]){
            int nextPoint = next.first;
            int nextCost = next.second;

            if(dist[nextPoint]>dist[node.first]+nextCost && dist[node.first]+nextCost<=c){
                dist[nextPoint]=dist[node.first]+nextCost;
                int tempMaxNum = max(node.second,nextCost);
                pq.push({nextPoint,tempMaxNum});
            }

        }
    }

    // for(int i=0;i<n;i++){
    //     cout<<dist[i]<<endl;
    // }
    cout<<ans<<"\n";

}