#include<bits/stdc++.h>

using namespace std;
long long n;
long long k;

long long oneCount(long long num){
    long long cnt = 0L;
    while(1){
        if(num==1){
            cnt++;
            break;
        }
        if(num%2==0){
            num/=2;
        }else{
            cnt++;
            num/=2;
        }
    }
    return cnt;
}

int main(){
    cin>>n>>k;
    long long tot = n;
    /*
    tot를 늘려가면서 k개 이하로 1의 개수가 나오는 지점이 물병의
    최소값을 만들어낼 수 있는 것!
    */
   while(1){
    long long cnt = oneCount(tot);
    if(cnt<=k){
        break;
    }else{
        tot++;
    }
   }
   cout<<tot-n<<"\n";


}