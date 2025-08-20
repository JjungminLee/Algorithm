#include<bits/stdc++.h>
using namespace std;

int n,m,k;
// 다음 인덱스, 거리
vector<pair<int,long long>>arr[100001];
long long dist[100001]; // 각 도시에서 면접장까지 최단거리
vector<int>v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
  
    for(int i=0;i<m;i++){
        int u,v;
        long long c;
        cin>>u>>v>>c;
        arr[v].push_back({u,c});
    }
    for(int i=1;i<=n;i++){
        dist[i]=1e18;
    }
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        dist[num]=0;
        pq.push({0,num});
    }

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        long long len = cur.first;
        int curNode = cur.second;
        if(len>dist[curNode]) continue;
        for(auto next:arr[curNode]){
            int nextIdx = next.first;
            long long nextLen = next.second;
            if(dist[nextIdx]>dist[curNode]+nextLen){
                dist[nextIdx]=dist[curNode]+nextLen;
                pq.push({dist[nextIdx],nextIdx});
            }
        }
    }
    int maxIdx = 0;
    long long maxAns = 0;
    for(int i=1;i<=n;i++){
        if(dist[i]>maxAns){
            maxAns=dist[i];
            maxIdx=i;
        }
    }
    cout<<maxIdx<<"\n";
    cout<<maxAns<<"\n";

}