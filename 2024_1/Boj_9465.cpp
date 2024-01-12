
#include <bits/stdc++.h>
using namespace std;

int T;
int dp[2][100000];
int arr[2][100000];
vector <int> vAns;
void init(){
    for(int i=0;i<2;i++){
        for(int j=0;j<100000;j++){
            dp[i][j]=0;
            arr[i][j]=0;
        }
    }
}

int main(){

    cin>>T;
 
    for(int i=0;i<T;i++){
        int N;
        cin>>N;

        init();
   
        
        for(int j=0;j<2;j++){
            for(int k=0;k<N;k++){
                cin>>arr[j][k];
            }

        }
        if(N==1){
            dp[0][0]=arr[0][0];
            dp[1][0]=arr[1][0];
        }
        else if(N==2){
            dp[0][0]=arr[0][0];
            dp[1][0]=arr[1][0];
            dp[0][1]=dp[1][0]+arr[0][1];
            dp[1][1]=dp[0][0]+arr[1][1];
        }
       else{
            dp[0][0]=arr[0][0];
            dp[1][0]=arr[1][0];
            dp[0][1]=dp[1][0]+arr[0][1];
            dp[1][1]=dp[0][0]+arr[1][1];
            for(int j=2;j<N;j++){
                dp[0][j]=max(dp[0][j],dp[0][j-2]+arr[0][j]);
                dp[0][j]=max(dp[0][j],dp[1][j-2]+arr[0][j]);
                dp[0][j]=max(dp[0][j],dp[1][j-1]+arr[0][j]);
                dp[1][j]=max(dp[1][j],dp[0][j-2]+arr[1][j]);
                dp[1][j]=max(dp[1][j],dp[0][j-1]+arr[1][j]);
                dp[1][j]=max(dp[1][j],dp[1][j-2]+arr[1][j]);

            }
       }
        int res=0;
     
        for(int j=0;j<2;j++){
            for(int k=0;k<N;k++){
                res=max(res,dp[j][k]);
        
            }
       }
       vAns.push_back(res);
    }
    for(int i=0;i<vAns.size();i++){
        cout<<vAns[i]<<endl;
    }

}