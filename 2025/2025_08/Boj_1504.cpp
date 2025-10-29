#include<bits/stdc++.h>
using namespace std;

int n,e;
vector<pair<int,long long>>v[801];
int v1;
int v2;
long long dist[801];
long long distv1[801];
long long distv2[801];

int main(){
    cin>>n>>e;
    for(int i=0;i<=n;i++){
        dist[i]=1e10;
        distv1[i]=1e10;
        distv2[i]=1e10;
    }
    for(int i=0;i<e;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin>>v1>>v2;

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    dist[1]=0;
    pq.push({0,1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curNode = cur.second;
        long long curLen = cur.first;
        for(auto next:v[curNode]){
            int nextNode = next.first;
            long long nextLen = next.second;
            if(dist[nextNode]>dist[curNode]+nextLen){
                dist[nextNode]=dist[curNode]+nextLen;
                pq.push({dist[nextNode],nextNode});

            }
        }
    }
    
    pq = priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>();
    distv1[v1]=0;
    pq.push({0,v1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curNode = cur.second;
        long long curLen = cur.first;

        for(auto next:v[curNode]){
            int nextNode = next.first;
            long long nextLen = next.second;
           
            if(distv1[nextNode]>distv1[curNode]+nextLen){
                distv1[nextNode]=distv1[curNode]+nextLen;
                pq.push({distv1[nextNode],nextNode});

            }
        }
    }

    pq = priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>();
    distv2[v2]=0;
    pq.push({0,v2});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curNode = cur.second;
        long long curLen = cur.first;

        for(auto next:v[curNode]){
            int nextNode = next.first;
            long long nextLen = next.second;
           
            if(distv2[nextNode]>distv2[curNode]+nextLen){
                distv2[nextNode]=distv2[curNode]+nextLen;
                pq.push({distv2[nextNode],nextNode});

            }
        }
    }
  
    // 1~v1 v1~v2 v2~N
    long long case1 = dist[v1]+distv1[v2]+distv2[n];


    // 1~v2 v2~v1 v1~N
    long long case2 = dist[v2]+distv2[v1]+distv1[n];

    long long answer = case1<case2?case1:case2;
    if(answer>=1e10){
        cout<<-1<<"\n";
    }else{
        cout<<answer<<"\n";
    }
}