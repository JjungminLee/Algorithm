#include<bits/stdc++.h>
using namespace std;

map<pair<string,string>,int> mp;
int main(){
    int n;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        string city,state;
        cin>>city>>state;
        string ncity = city.substr(0,2);
        string nstate = state.substr(0,2);
        if(ncity!=nstate){
            mp[{ncity,nstate}]++;
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        string a = it->first.first;
        string b = it->first.second;
        if(mp[{b,a}]>0){
            ans +=mp[{b,a}]*mp[{a,b}];

        }
    }
    cout<<ans/2<<endl;
}