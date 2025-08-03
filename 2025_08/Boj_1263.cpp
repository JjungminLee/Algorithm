#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,long long>> v;

bool comparators(pair<int,long long> a, pair<int,long long> b){
    return a.second>b.second;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t,s;
        cin>>t>>s;
        v.push_back({t,s});

    }
    sort(v.begin(),v.end(),comparators);
    long long time = v[0].second;
    for(int i=0;i<n;i++){
        time = min(time,v[i].second); // 마감시간을 지켜야하기 때문에 필요..! 더 늦은 시간에 끝낼수도 있어서
        time -= v[i].first;
    }
    if(time<0){
        cout<<-1<<endl;
    }else{
        cout<<time<<endl;
    }
    
}