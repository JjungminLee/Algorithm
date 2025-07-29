#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;

struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second; // 끝나는 시간이 빠른 순 (오름차순)
    }
};

int main(){
    int n;
    int ans=0;
    cin>>n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    for(int i=0;i<n;i++){
        int s,t;
        cin>>s>>t;
        pq.push({s,t});
    }

    auto cur = pq.top();
    pq.pop();
    ans++;

    while(!pq.empty()){
        auto next = pq.top();
        pq.pop();
        if(next.first>=cur.second){
           
            cur=next;
            ans++;
        }

    }
    cout<<ans<<endl;
}