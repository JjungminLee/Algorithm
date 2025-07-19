#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10001];
// 놀이기구 탑승인원
long long getCount(long long t){
    long long cnt=m;
    for(int i=0;i<m;i++){
        cnt+=t/arr[i];
    }
    return cnt;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }

    long long left=0;
    long long right=2e12;
    long long time=0;
    int idx=0;
    if(n<=m){
        cout<<n<<endl;
        return 0;
    }
    while(left<=right){
        long long mid = (left+right)/2;
        if(getCount(mid)>=n){
            time=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    // 1분전까지 태운 탑승자 수
    long long totalCnt = getCount(time-1);
    idx=0;
    for(int i=0;i<m;i++){
            if(time%arr[i]==0){
                totalCnt++;
                if(totalCnt==n){
                    cout<<i+1<<endl;
                    return 0;
                }
            }
    }

}