#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
    cin>>n>>k;
    long long left=0;
    long long right=n*n;
    while(left<=right){
        long long mid=(left+right)/2;
        long long num=0;
        for(int i=1;i<=n;i++){
            num+=min(mid/i,n);
        }
  
        if(num>=k){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    cout<<left<<endl;

}