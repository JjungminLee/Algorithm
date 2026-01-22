#include<bits/stdc++.h>

using namespace std;

int T;
int N,M;
int K;
vector<pair<int,int>>v[50000];

int dijkstra(vector<int>friends){

    int dist[50000];
    long long minDist = LLONG_MAX;
    int minIdx=0;

    // 시작지점 부터
    for(int i=1;i<=N;i++){
        for(int j=0;j<50000;j++){
            dist[j]=INT_MAX;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        dist[i]=0;
        //다익스트라는 거리,인덱스 로 큐에 넣어야
        pq.push({0,i});

        while(!pq.empty()){
            auto cur = pq.top();
            int d = cur.first;
            int idx = cur.second;
            pq.pop();

            for(auto next:v[idx]){
                int nextIdx = next.first;
                int nextD = next.second;
                if(dist[nextIdx]>dist[idx]+nextD){
                    dist[nextIdx] = dist[idx]+nextD;
                    pq.push({dist[nextIdx],nextIdx});
                }
            }
        }

        long long sum = 0;
        // 친구들 지점에서 끝나는 지점(i) 까지 최단거리
        for(int f:friends){
            sum+=dist[f];
        }
        if(sum<minDist){
            minDist=sum;
            minIdx = i;
        }
    }
    
    return minIdx;
}

int main(){
    cin>>T;
    for(int i=0;i<T;i++){
       
        cin>>N>>M;
        for(int j=1;j<50000;j++){
            v[j].clear();
        }
        for(int j=0;j<M;j++){
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        cin>>K;
        vector<int> friends;
        for(int j=0;j<K;j++){
            int num;
            cin>>num;
            friends.push_back(num);
        }
        int idx = dijkstra(friends);

        cout<<idx<<"\n";
        
    }

}