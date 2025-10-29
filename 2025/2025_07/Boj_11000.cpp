#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>v;

struct Compare {
    bool operator()(pair<long long,long long> a, pair<long long,long long> b) {
        return a.second > b.second; 
    }
};

int main(){
    int n;
    int ans=0;
    cin>>n;
    vector<pair<int,int>>v;
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, Compare> pq;
    for(int i=0;i<n;i++){
        long long s,t;
        cin>>s>>t;
        v.push_back({s,t});
    }
    sort(v.begin(),v.end());
    pq.push({v[0].first,v[0].second});
    for(int i=1;i<n;i++){
        if(!pq.empty()){
            auto cur = pq.top();
            if(v[i].first<cur.second){
                pq.push({v[i].first,v[i].second});
            }else{
                pq.pop();
                pq.push({v[i].first,v[i].second});
            }

        }
    }
    cout<<pq.size()<<endl;

}