#include<bits/stdc++.h>
using namespace std;

int n;

// 위상정렬
vector<vector<int>>graph(501);
int buildTime[501];
int dp[501];
int degree[501];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int num;
        int idx=0;
        while(1){
            cin>>num;
            if(num==-1){
                break;
            }
            if(idx==0){
                buildTime[i]=num;
            }else{
                graph[num].push_back(i);
                degree[i]++;
            }
            idx++;
        }
        
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            q.push(i);
            dp[i]=buildTime[i];
        }
    }

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int next:graph[cur]){
            dp[next]=max(dp[next],dp[cur]+buildTime[next]);
            degree[next]--;
            if(degree[next]==0){
                q.push(next);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dp[i]<<endl;
    }

}