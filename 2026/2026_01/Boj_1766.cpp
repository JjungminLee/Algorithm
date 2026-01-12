#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> inDegree;
vector<int>graph[32005];

int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        inDegree.push_back(0);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        inDegree[b]++;
        graph[a].push_back(b);
        
    }


    priority_queue<int,vector<int>,greater<>>pq;

    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            pq.push(i);
        }
    }

    for(int i=0;i<n;i++){
        if(pq.empty()) return 0;

        int cur = pq.top();
        pq.pop();

        cout<<cur<<" ";

        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(--inDegree[next]==0){
                pq.push(next);
            }
        }
    }
    cout<<"\n";

}