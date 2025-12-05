#include<bits/stdc++.h>

using namespace std;

long long n;
long long m;
vector<long long>v;

int main(){
    cin>>n>>m;

    for(int i=0;i<m;i++){
        long long num;
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    long long left=1;
    long long right = v[m-1];
    long long ans = 0;
    
    while(left<=right){
        long long mid = (left+right)/2;
        long long cnt = 0;

        for(int i=0;i<v.size();i++){
            cnt+=(v[i]/mid);
            if(v[i]%mid!=0){
                cnt++;
            }
        }
        if(cnt<=n){
            ans=mid;
            right = mid-1;
        }else{
            left=mid+1;
        }
    }
    cout<<ans<<"\n";

}