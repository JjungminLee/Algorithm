#include<bits/stdc++.h>

using namespace std;
#define MAX 250005

long long n;
long long arr[MAX];
long long dp[MAX];

int main(){
    while(1){
        cin>>n;
        if(n==0) break;
        for(int i=0;i<MAX;i++){
            arr[i]=0;
            dp[i]=LLONG_MIN;
        }
     
        for(int i=0;i<n;i++){
            cin>>arr[i];
            dp[i]=arr[i];
        }
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i],dp[i-1]+arr[i]);
        }

        long long ans = LLONG_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        cout<<ans<<"\n";
    }

}