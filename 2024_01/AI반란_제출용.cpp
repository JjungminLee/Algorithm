#include<iostream>
#include<algorithm>
using namespace std;
int dp[51][51][51]; // 횟수 힘 지 
int MAX = 10000000;
int T;

void init(){
      for(int i=1;i<51;i++){
        for(int j=0;j<51;j++){
            for(int k=0;k<51;k++){
                dp[i][j][k]=MAX;
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin>>T;
  
    for(int i=0;i<T;i++){
        int N;
        cin>>N;
        init();
         int res = MAX;
        for(int j=1;j<=N;j++){
            int a,b,c;
            cin>>a>>b>>c;
           
            
            if(j==1){
                dp[1][1][0]=b+c;
                dp[1][0][1]=a+c;
                dp[1][0][0]=a+b;
            }else{
                for(int k=0;k<=N;k++){
                    for(int m=0;m<=N;m++){
                        if(k+m>N&&N-(k+m)>N&&N-(k+m)<0){
                            break;
                        }
                      
                        if(k!=0){
                            dp[j][k][m] = min(dp[j][k][m],dp[j-1][k-1][m]+b+c);

                        }
                        if(m!=0){
                            dp[j][k][m] = min(dp[j][k][m],dp[j-1][k][m-1]+a+c);
                        }
                        if(N-k-m!=0){
                            dp[j][k][m] =min(dp[j][k][m],dp[j-1][k][m]+a+b);
                        }

                        cout<<j<<" "<<k<<" "<<m<<" "<<N-k-m<<" "<<endl;
                        cout<<dp[j][k][m]<<endl;
                    }

                }

         

        
               
            }
            
        }

        for(int j=1;j<N;j++){
            for(int k=1;k<N;k++){
                
                if(j+k<N){
                    res=min(res,dp[N][j][k]);
                    cout<<j<<k<<N-j-k<<endl;
                    cout<<res<<endl;
                }

            }
        }

         cout<<"#"<<i+1<<" "<<res<<endl;

        
        
      

        
    }

    

}