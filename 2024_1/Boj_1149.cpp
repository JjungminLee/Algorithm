#include <bits/stdc++.h>

using namespace std;
int arr[1001][3];
int dp[1010][3];
int N;
int ans = INT_MAX;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[i][0]=a;
        arr[i][1]=b;
        arr[i][2]=c;
    }
 
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    for(int i=1;i<N;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i][2];
    }
    for(int i=0;i<3;i++){
        ans = min(ans,dp[N-1][i]);
    }
    
    cout<<ans<<endl;
    


}