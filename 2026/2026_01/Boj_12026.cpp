#include<bits/stdc++.h>

using namespace std;

int n;
char arr[1005];
int dp[1005];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<1005;i++){
        dp[i]=1e9;
    }
    dp[0]=0;

    for(int i=0;i<n-1;i++){
        char cur=arr[i];
        if(dp[i]==1e9) continue;
        for(int j=i+1;j<n;j++){
            char next = arr[j];
            if(cur=='B'&&next=='O'){
                dp[j]=min(dp[j],dp[i]+(j-i)*(j-i));
            }else if(cur=='O'&&next=='J'){
                dp[j]=min(dp[j],dp[i]+(j-i)*(j-i));
            }
            else if(cur=='J'&&next=='B'){
                dp[j]=min(dp[j],dp[i]+(j-i)*(j-i));
            }

        }

    }
    if(dp[n-1]==1e9){
        cout<<-1<<"\n";
    }else{
        cout<<dp[n-1]<<"\n";
    }


}