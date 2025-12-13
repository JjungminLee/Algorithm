#include<bits/stdc++.h>
using namespace std;

int n,s,m;
int arr[55];
bool dp[55][1005];
int ans;

int main(){
    cin>>n>>s>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    dp[0][s]=true;
    for(int i=1;i<=n;i++){
        for(int v=0;v<=m;v++){
            if(dp[i-1][v]){
                if(v-arr[i]>=0) dp[i][v-arr[i]]=true;
                if(v+arr[i]<=m) dp[i][v+arr[i]]=true;
            }
        }
    }
    ans = -1;
    for(int v=m;v>=0;v--){
        if(dp[n][v]){
            ans = v;
            break;
        }
    }
    cout<<ans<<"\n";
}