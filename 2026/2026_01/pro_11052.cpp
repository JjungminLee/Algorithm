#include<bits/stdc++.h>

using namespace std;

int N;
int dp[1005];
int arr[1005];

int main(){
    cin>>N;
    
    for(int i=1;i<=N;i++){
        dp[i]=INT_MIN;
    }
    for(int i=1;i<=N;i++){
        cin>>dp[i];
    }

    for(int i=2;i<=N;i++){
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i-j]+dp[j],dp[i]);
        }
    }

    cout<<dp[N]<<"\n";

}