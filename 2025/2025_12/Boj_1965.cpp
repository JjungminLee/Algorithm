#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int dp[1005];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[0]=1;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        
    }
    int maxNum = 0;
    for(int i=0;i<n;i++){
        maxNum=max(dp[i],maxNum);
    }
    
    cout<<maxNum<<"\n";

}