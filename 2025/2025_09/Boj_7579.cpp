#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 10000001
int N,M;
int arr[200];
int c[200];
int dp[MAX_SIZE];
int main(){

    cin>>N>>M;
    int sumMem = 0;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        sumMem+=arr[i];
    }

    for(int i=0;i<N;i++){
        cin>>c[i];
    }
    
    for(int i=0;i<=sumMem;i++){
        dp[i]=MAX_SIZE;
    }
    dp[0]=0;
 

    for(int i=0;i<N;i++){
        // 음수 인덱스 나오면 안됨
        for(int j=sumMem;j>=arr[i];j--){
            dp[j]=min(dp[j],dp[j-arr[i]]+c[i]);
        }

    }
    int memAns = MAX_SIZE;
    for(int i=M;i<=sumMem;i++){
        memAns=min(dp[i],memAns);
    }
    cout<<memAns<<endl;
}