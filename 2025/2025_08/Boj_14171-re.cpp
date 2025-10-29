#include<bits/stdc++.h>
using namespace std;
int n;
map<pair<string,string>,int> mp;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string a;
        string b;
        cin>>a>>b;
        string na = a.substr(0,2);
        if(na!=b){
            mp[{na,b}]++;
        }
    }
    int ans=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        string a = it->first.first;
        string b = it->first.second;
        if(mp[{b,a}]>0){
            ans+=(mp[{a,b}]*mp[{b,a}]);
        }
    }
    cout<<ans/2<<endl;

}