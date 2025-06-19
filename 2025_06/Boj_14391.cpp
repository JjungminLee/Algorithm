#include<bits/stdc++.h>
using namespace std;
int n,m;
int row;
int col;

int arr[5][5];
int ans;

// x,y를 가로방향으로 자를거냐, 세로방향으로 자를거냐 -> 상태가 2가지 -> 비트마스킹
// n행m열을 1차원 배열로

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            arr[i][j]=str[j]-'0';
        }
    }
    // 1<<(n*m) -> 모든 경우의 수
    // 종이를 자르는지 안자르는지 2^(n*m)
    for(int num=0;num<(1<<(n*m));num++){
        int sum=0;
        // 가로로 자르기
        for(int i=0;i<n;i++){
            int val=0;
            for(int j=0;j<m;j++){
                //가로면 0 세로면 1
                // (i,j) 값과 현재 값이 0인지 1인지
                int bit = (num>>(i*m+j))&1;
                if(bit==0){
                    // 현재 위취가 가로로 잘리면 누적
                    val=10*val+arr[i][j];
                    
                }else{
                    // 세로로 잘리면 끊기
                    sum+=val;
                    val=0;
                }
            }
            // 중요! 마지막 가로숫자 더하기
            sum+=val;
        }

        //세로
        for(int j=0;j<m;j++){
            int val=0;
            for(int i=0;i<n;i++){
                int bit = (num>>(i*m+j))&1;
                if(bit==1){
                    // 세로로 잘리면 누적
                    val=10*val+arr[i][j];
                }else{
                    // 가로로 잘리면 끊기
                    sum+=val;
                    val=0;
                   
                }
            }
            // 중요! 마지막 세로숫자 더하기
            sum+=val;
        }
        ans=max(ans,sum);

        
    }
    cout<<ans<<endl;
}