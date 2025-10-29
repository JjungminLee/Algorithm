#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10000001
int N,M;
int arr[200];
long long c[200];
long long dp[MAX_SIZE];
int main(){

    cin>>N>>M;
    long long sumMem = 0;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        sumMem+=arr[i];
    }

    for(int i=0;i<N;i++){
        cin>>c[i];
    }
    
    for(int i=0;i<=sumMem;i++){
        dp[i]=1e10;
    }
    dp[0]=0;
 

    for(int i=0;i<N;i++){
        // 음수 인덱스 나오면 안됨
        for(int j=sumMem;j>=arr[i];j--){
            dp[j]=min(dp[j],dp[j-arr[i]]+c[i]);
        }

    }
    long long memAns = 1e10;
    for(int i=M;i<=sumMem;i++){
        memAns=min(dp[i],memAns);
    }
    cout<<memAns<<endl;
}