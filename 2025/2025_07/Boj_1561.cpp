#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10001];
int idx=0;
long long getCount(long long t){
    long long cnt = m;
    for(int i=0;i<m;i++){
        cnt+=t/arr[i]; // arr[i]가 t분동안 태울 수 있는것 누적
    }
    return cnt;
}
int main(){
    cin>>n>>m;
    long long sum=0;
    for(int i=0;i<m;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    long long left =0;
    long long right = 6e10;
    long long time=0;
    if(n<=m){
        cout<<n<<endl;
        return 0;
    }
    while(left<=right){
        long long mid = (left+right)/2;
        
        if(getCount(mid)>=n){
            time = mid;
            right = mid-1;

        }else{
            left = mid+1;
        }
    }
    long long riders = getCount(time-1); // time-1까지 탑승한 인원수
        idx=0;
    
        for(int i=0;i<m;i++){
            if(time%arr[i]==0){
                riders++;
                if(riders==n){
                   idx=i+1;
                    break;
                }
            }
        }
    cout<<idx<<endl;

}