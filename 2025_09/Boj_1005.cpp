#include<bits/stdc++.h>
using namespace std;
int T;
int N,K,W;

int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N>>K;
        vector<int>buildings(N+1);
        vector<int>graph[1001];
        int inDegree[1001]={0,};
        int dp[1001]={0,};
        queue<int>q;

        for(int j=1;j<=N;j++){
            cin>>buildings[j];
        }

        for(int j=0;j<K;j++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            inDegree[b]++;
        }
        cin>>W;

        for(int j=1;j<=N;j++){
            if(inDegree[j]==0){
                q.push(j);
                dp[j]=buildings[j];
            }

        }
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int k=0;k<graph[cur].size();k++){
                int next = graph[cur][k];
                // 특정건물을 다 지을때까지 최소 시간 => max사용!
                dp[next]=max(dp[next],dp[cur]+buildings[next]);
                inDegree[next]--;
                if(inDegree[next]==0){
                    q.push(next);
                }
            }
        }

        cout<<dp[W]<<endl;

    }

}