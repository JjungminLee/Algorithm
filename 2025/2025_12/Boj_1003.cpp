#include<bits/stdc++.h>

using namespace std;

int t;
int dp0[45];
int dp1[45];


int main(){
    cin>>t;
   
    dp0[0]=1;
    dp0[1]=0;
    dp0[2]=1;
    dp0[3]=1;

    dp1[0]=0;
    dp1[1]=1;
    dp1[2]=1;
    dp1[3]=2;
    for(int i=4;i<45;i++){
        dp0[i]=dp0[i-1]+dp0[i-2];
        dp1[i]=dp1[i-1]+dp1[i-2];
    }

    for(int i=0;i<t;i++){
        int num;
        cin>>num;
        cout<<dp0[num]<<" "<<dp1[num]<<"\n";
    }


}