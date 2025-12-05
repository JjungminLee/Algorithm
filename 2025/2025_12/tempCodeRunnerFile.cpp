#include<bits/stdc++.h>

using namespace std;

long long n;
long long m;
vector<long long>v;

int main(){
    cin>>n>>m;
    long long left=0;
    long long right = 0;
    long long num=0;
    long long ans = LLONG_MAX;

    for(int i=0;i<m;i++){
        long long num;
        cin>>num;
        right+=num;
        v.push_back(num);
    }
    
    while(left<=right){
        long long mid = (left+right)/2;
        long long cnt = 0;

        for(int i=0;i<v.size();i++){
            if(v[i]>=mid){
                if(v[i]%mid==0){
                    cnt+=(v[i]/mid);
                }else{
                    if(v[i]/mid>1){
                        cnt+=(v[i]/mid);
                    }else{
                        cnt+=((v[i]/mid)+1);
                    }
                }
            }else{
                cnt++;
            }
        }

        if(cnt==n){
            num = mid;
            long long curMaxNum = 0;
            for(int i=0;i<v.size();i++){
                if(v[i]%num==0){
                    if(curMaxNum<(v[i]/mid)){
                        curMaxNum = (v[i]/mid);
                    }
                }else{
                    int temp = 0;
                    if(v[i]/mid>1){
                        temp = max(mid,mid+(v[i]%mid));
                    }else{
                       temp = max(mid,v[i]%mid);
                    }
                    if(temp>curMaxNum){
                        curMaxNum=temp;
                    }
                }
            }
            ans = min(curMaxNum,ans);
            right = mid-1;
        }else if(cnt<n){
            right = mid-1;
        }else if(cnt>n){
            left = mid+1;
        }
    }
    cout<<ans<<"\n";
}