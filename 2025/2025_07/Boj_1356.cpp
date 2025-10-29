#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>v;
vector<int>ans;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    for(int i=0;i<n;i++){
        auto it = lower_bound(ans.begin(),ans.end(),v[i]);
        if(it==ans.end()){
            ans.push_back(v[i]);
        }else{
            *it=v[i];
        }
    }
    cout<<n-ans.size()<<endl;
}