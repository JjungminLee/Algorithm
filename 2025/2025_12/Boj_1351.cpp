#include<bits/stdc++.h>

using namespace std;
long long n;
long long p;
long long q;
map<long long,long long>dp;

long long calc(long long x){
    if(x==0) return 1;
    if(dp.count(x)) return dp[x];
    return dp[x]=calc(x/p)+calc(x/q);
}

int main(){

    cin>>n>>p>>q;
    cout<<calc(n)<<"\n";
    
}