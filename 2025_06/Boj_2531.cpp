#include<bits/stdc++.h>
using namespace std;

int n,d,k,c;
int arr[30001];
int sortArr[3001];
int ans;
int main(){

    // set을 쓰지 않고 arr사용

    cin>>n>>d>>k>>c;
    int kinds=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    
    }
    for(int i=0;i<k;i++){
        if(sortArr[arr[i]]==0){
            kinds++;
        }
        sortArr[arr[i]]++;
    }
    if(sortArr[c]==0){
        ans=kinds+1;
    }else{
        ans=kinds;
    }

    for(int i=k;i<n+k;i++){
        sortArr[arr[i-k]]--;
        if(sortArr[arr[i-k]]==0){
            kinds--;
        }
        if(sortArr[arr[i%n]]==0){
            kinds++;
        }
          sortArr[arr[i%n]]++;
        
        if(sortArr[c]==0){
            ans=max(ans,kinds+1);
        }else{
            ans=max(ans,kinds);
        }
      
        

    }
    cout<<ans<<endl;
    
}