#include <bits/stdc++.h>

using namespace std;
int N;
int dp[10000000];
int main(){
    cin>>N;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=N;i++){
        if(i%2==0){
            dp[i]=2*dp[i-2]-1+dp[i-1]-1;
        }else{
            dp[i]=2*dp[i-2]+dp[i-1]-1;
        }
    }
    cout<<dp[N]%15746<<endl;
}