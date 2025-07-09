#include<bits/stdc++.h>
using namespace std;

int n;
long long arr[51];
int ans=0;
int main(){
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        long long std = arr[i];

        double minH=1e10;
        int lcnt=0;
        for(int j=i-1;j>=1;j--){
            double h = ((arr[j]-arr[i])/(double)(j-i));
            if(h<minH){
                minH=h;
                lcnt++;
            }

        }

        double maxH=-1e10;
        int rcnt=0;
        for(int j= i+1;j<=n;j++){
            double h = ((arr[j]-arr[i])/(double)(j-i));
            if(h>maxH){
                maxH=h;
                rcnt++;
            }

        }

        ans=max(ans,lcnt+rcnt);
      
    }
    if(n==1){
        cout<<0<<endl;
    }else{
        cout<<ans<<endl;
    }
}
