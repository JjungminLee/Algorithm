#include<bits/stdc++.h>

using namespace std;

int n;
// {포인트, 등장횟수}
map<char,pair<long long,int>>mp;
vector<string>v;
// {포인트, 등장횟수}
vector<pair<pair<long long,int>,char>> vp;
map<char,int>mp_point;
long long ans=0L;

bool compares(pair<pair<long long,int>,char>a,pair<pair<long long,int>,char>b){
    if(a.first.first==b.first.first){
        if(a.first.second==b.first.second){
            return a.first<b.first;
        }
        return a.first.second>b.first.second;
    }
    return a.first.first>b.first.first;
}

int main(){

    cin>>n;
    bool leading[256] = {false};
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);

        leading[(unsigned char)str[0]] = true;  
        int size = str.size();
        for(int j=0;j<size;j++){
            char ch = str[j];
            long long point = pow(10, size - j - 1);
            mp[ch].first+=point;
            mp[ch].second+=1;
        }
    }

    for(auto it=mp.begin();it!=mp.end();it++){
        pair<long long,int> p = it->second;
        //cout<<"first "<<it->first<<" p "<<p.first<<" "<<p.second<<endl;
        vp.push_back({{p.first,p.second},it->first});
    }
    sort(vp.begin(),vp.end(),compares);

    int curNum = 9;
    char zeroCandidate = 0;

    if(vp.size()>=10){
        for(int i = vp.size()-1; i>=0; i--){
            char c = vp[i].second;
            if(!leading[(unsigned char)c]){
                zeroCandidate = c;
                break;
            }
        }
        for(int i=0;i<vp.size();i++){
            char c = vp[i].second;
            if(c == zeroCandidate) continue;  
            mp_point[c] = curNum;
            curNum--;
        }
        mp_point[zeroCandidate] = 0;
    }else{
        for(int i=0;i<vp.size();i++){
            char c = vp[i].second;
            mp_point[c] = curNum;
            curNum--;
        }

    }

    // for(auto it=mp_point.begin();it!=mp_point.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }

    for(string str:v){
        long long cur = 0;
        for(char ch:str){
            cur = cur*10+mp_point[ch];
        }
        ans+=cur;
    }

    cout<<ans<<"\n";

    
}