#include<bits/stdc++.h>

using namespace std;

int N,K;
int dp[20010];
int times[1001];
int importances[1001];
int main(){
    cin>>N>>K;
    for(int i=0;i<K;i++){
        int I,T;
        cin>>I>>T;
        //dp[시간]=최대 중요도
        times[i]=T;
        importances[i]=I;
    }

    // 과목 중요도
    for(int i=0;i<K;i++){
        for(int t=N;t>=times[i];t--){
            dp[t]=max(dp[t],dp[t-times[i]]+importances[i]);
        }
    }

    cout<<dp[N]<<"\n";

}