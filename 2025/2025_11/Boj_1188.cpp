#include<bits/stdc++.h>

using namespace std;

int N,M;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    cin>>N>>M;
    int num = gcd(N,M);
    cout<<M-num<<"\n";
}