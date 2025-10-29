#include<bits/stdc++.h>

using namespace std;


int N;
long long DIV = 1000000;
long long dp[1005][2][3];

int main(){
    cin>>N;
    dp[0][0][0]=1; // 아무것도 안하는 상태

    for(int i=1;i<=N;i++){
        // 지각은 1번까지
        for(int j=0;j<=1;j++){
            // 결석은 두번까지
            for(int k=0;k<=2;k++){  

                // 점화식은 누적되는게 핵심

                long long prev = dp[i-1][j][k];

                //오늘 출석
                dp[i][j][0]=(dp[i][j][0]+prev)%DIV;

                //오늘 지각
                if(j<1){
                    dp[i][j+1][0]=(dp[i][j+1][0]+prev)%DIV;
                   
                }
                //오늘 결석
                if(k<2){
                    dp[i][j][k+1]=(dp[i][j][k+1]+prev)%DIV;
                }
            }
        }
    }

    long long ans=0;
    for(int j=0;j<=1;j++){
        for(int k=0;k<=2;k++){
            ans=(ans+dp[N][j][k])%DIV;
        }
    }

    cout<<ans<<"\n";

}

