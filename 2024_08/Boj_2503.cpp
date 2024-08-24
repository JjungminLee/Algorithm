#include<bits/stdc++.h>
using namespace std;
int n;
vector<tuple<int,int,int>>v;
vector<int>ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        int ball;
        int strike;
        cin>>num>>strike>>ball;
        v.push_back({num,strike,ball});

    }
    

    for(int i=123;i<=987;i++){
        int std=i;
        int h1=std/100;
        int t1=(std%100)/10;
        int o1=(std%100)%10;
        int fit=0;
        // 0이 중복
        if( t1==0 || o1==0){
            continue;
        }
        // 서로 같은 숫자일떄 -> 생각도 못함!
        if(h1==t1 || t1==o1||h1==o1){
            continue;
        }
            
        for(int j=0;j<n;j++){
            int num,ball,strike;
            tie(num,strike,ball)=v[j];
           
            int h2=num/100;
            int t2=(num%100)/10;
            int o2=(num%100)%10;
            
            int s=0;
            int b=0;

            //개별적 비교!
            if(h1==h2){
                s++;
            }
            if(t1==t2){
                s++;
            }
            if(o1==o2){
                s++;
            }
            if(h1==t2||h1==o2){
                b++;
            }
            if(t1==h2||t1==o2){
                b++;
            }
            if(o1==h2||o1==t2){
                b++;
            }
            if(strike==s&&ball==b){
                fit++;
            }
          
        }
       
        if(fit==n){
            ans.push_back(std);
        }
    }
    cout<<ans.size()<<endl;

  
}