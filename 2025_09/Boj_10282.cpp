#include<bits/stdc++.h>
using namespace std;
int tc;

struct Node{
    int times;
    int target;

};


int main(){
    cin>>tc;
    while(tc--){
        int n,d,c;
        cin>>n>>d>>c;
        c-=1;
        vector<Node>v[10001];
        int dist[10001];
        for(int i=0;i<10001;i++){
            dist[i]=1e9;
        }
        for(int i=0;i<d;i++){
            int a,b,s;
            cin>>a>>b>>s;
            a--;
            b--;
            v[b].push_back({s,a});
        }
        // 한 점에서 모든 점을 가는 경우
        // 시간, 다음타자
        // dist[인덱스]=  최소시간
        dist[c]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,c});

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int curTime = cur.first;
            int nextTarget = cur.second;
            if(curTime>dist[nextTarget]) continue;
            
            for(auto next:v[nextTarget]){
               if(dist[next.target]>curTime+next.times){
                    dist[next.target]=curTime+next.times;
                    pq.push({curTime+next.times,next.target});
                   
               }
            }

        }

        int maxTime=0;
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(dist[i]==1e9)continue;
            if(dist[i]!=1e9){
                cnt++;
            }
            if(dist[i]>maxTime){
                maxTime = dist[i];
                
            }

        }

        cout<<cnt<<" "<<maxTime<<"\n";


    }

}