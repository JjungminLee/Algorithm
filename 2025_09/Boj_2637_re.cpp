#include<bits/stdc++.h>

using namespace std;

#define MAX (15)

int N,M;

struct Node{
    int val;
    int cnt;
};

int inDegree[MAX];
int dp[MAX][MAX];
vector<Node>graph[MAX];

int main(){

    cin>>N;
    cin>>M;
    for(int i=0;i<M;i++){
        int x,y,k;
        cin>>x>>y>>k;
        graph[y].push_back({x,k});
        inDegree[x]++;
    }

    queue<int>q;

    for(int i=1;i<=N;i++){
        if(inDegree[i]==0){
            dp[i][i]=1;
            q.push(i);
        }
    }

    while(!q.empty()){
        int num = q.front();
        q.pop();

        for(Node next:graph[num]){
            for(int i=1;i<=N;i++){
                dp[next.val][i]+=dp[num][i]*next.cnt;
            }
            inDegree[next.val]--;
            if(inDegree[next.val]==0){
                q.push(next.val);
            }
        }

    }

    for(int i=1;i<=N;i++){
        if(dp[N][i]>0){
            cout<<i<<" "<<dp[N][i]<<"\n";
        }
    }

}