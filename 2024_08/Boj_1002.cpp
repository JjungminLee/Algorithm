#include <bits/stdc++.h>
using namespace std;
int t;
//원의 방정식
int main() {
    cin>>t;
    for(int i=0;i<t;i++){
        double a1,b1,a2,b2;
        double r1,r2;
        cin>>a1>>b1>>r1>>a2>>b2>>r2;
        double dist=sqrt(pow(a1-a2,2)+pow(b1-b2,2));
        // 동심원
        if(dist==0&&r1==r2){
            cout<<-1<<endl;
        }else if(abs(r1-r2)<dist&&dist<r1+r2){
            // 두 원이 두점에서 만남
            cout<<2<<endl;
        }else if(r1+r2==dist||abs(r1-r2)==dist){
            // 내접 또는 외접
            cout<<1<<endl;
        }else{
            // 한 원이 다른 원 안에 쏙 
            cout<<0<<endl;
        }
    }
}