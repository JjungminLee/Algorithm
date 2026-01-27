#include<bits/stdc++.h>

using namespace std;

int n;
int dp[1005];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i]=1e9;
    }
    for(int i=1;i<=n;i++){
        cin>>dp[i];
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]=min(dp[i],dp[i-j]+dp[j]);
        }
    }

    cout<<dp[n]<<"\n";
}