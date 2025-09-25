#include<bits/stdc++.h>

using namespace std;
int N,M;
//위상정렬 + dp
struct Node{
    int num;
    int cnt;

};
int basicCnt = 0;
int midCnt = 0;

vector<Node>graph[105];
int inDegree[105];
int dp[105][105]; //dp[x][i] = x를 만드는데 필요한 기본부품 i의 개수

int main(){
    cin>>N;
    cin>>M;
    for(int i=0;i<M;i++){
        int x,y,k;
        cin>>x>>y>>k;
        graph[y].push_back({x,k}); // 기본 부품y를 K개 가지고 x만듦
        inDegree[x]++;
    }

    queue<int>q;

    for(int i=1;i<=N;i++){
        //기본부품
        if(inDegree[i]==0){
            dp[i][i]=1;
            q.push(i);
        }
    }

    while(!q.empty()){
        // 기본 부품 부터 처리하게 됨
        int num = q.front();
        q.pop();
        for(Node node:graph[num]){
            for(int i=1;i<=N;i++){
                // 중간부품을 만드는데 필요한 기본부품 i의 개수
                dp[node.num][i]+=dp[num][i]*node.cnt;
            }
            inDegree[node.num]--;
            if(inDegree[node.num]==0){
                q.push(node.num);
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(dp[N][i]>0){
            cout<<i<<" "<<dp[N][i]<<"\n";
        }
    }

}