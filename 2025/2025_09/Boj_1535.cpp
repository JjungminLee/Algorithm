#include<bits/stdc++.h>

using namespace std;

int N;
int dp[101];
int L[101];
int J[101];
int main(){
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>L[i];
    }
    for(int i=0;i<N;i++){
        cin>>J[i];
    }

    for(int i=0;i<N;i++){
        for(int j=99;j>=L[i];j--){
            dp[j]=max(dp[j],dp[j-L[i]]+J[i]);
        }
    }
    int ans = 0;
    for(int i=1;i<=100;i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";

}