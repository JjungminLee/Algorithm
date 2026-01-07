#include<bits/stdc++.h>

using namespace std;

int n;
vector<long long>v;
int ans;

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        long long num;
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());
    
    for(int i=0;i<n;i++){
        long long target = v[i];

        int l=0;
        int r=n-1;

        while(l<r){
            if(l==i){
                l++;
                continue;
            }
            if(r==i){
                r--;
                continue;
            }

            long long sum = v[l]+v[r];
            if(sum==target){
                ans++;
                break;
            }else if(sum<target){
                l++;
            }else{
                r--;
            }
        }
    }
    cout<<ans<<"\n";
    
}