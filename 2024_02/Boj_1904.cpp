#include <bits/stdc++.h>

using namespace std;
int N;
long long dp[10000000];
int main(){
    cin>>N;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=N;i++){
        dp[i]=(dp[i-1]+dp[i-2])%15746;
    }
    cout<<dp[N]<<endl;
}