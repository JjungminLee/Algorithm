#include<bits/stdc++.h>

using namespace std;

int n;
map<char,int>mp;
vector<string>v;
vector<pair<int,char>> vp;
map<char,int>mp_point;
long long ans;

bool compares(pair<int,char>a,pair<int,char>b){
    return a.first>b.first;
}

int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
        int size = str.size();
        for(int j=0;j<size;j++){
            char ch = str[j];
            int point = size-j;
            mp[ch]+=point;
        }
    }

    for(auto it=mp.begin();it!=mp.end();it++){
        vp.push_back({it->second,it->first});
    }
    sort(vp.begin(),vp.end(),compares);

    int curNum = 9;

    for(int i=0;i<vp.size();i++){
        mp_point[vp[i].second] = curNum-i;
    }

    for(auto it=mp_point.begin();it!=mp_point.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    for(string str:v){
        int size = str.size();
        long long curMul = pow(10,size-1);
        for(int i=0;i<size;i++){
            ans+=(curMul*mp_point[str[i]]);
            curMul/=10;
        }
    }

    cout<<ans<<"\n";

    
}