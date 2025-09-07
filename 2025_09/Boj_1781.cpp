#include<bits/stdc++.h>
using namespace std;
int N;
struct Node{
    long long deadline;
    long long cnt;
};

vector<Node>v;

bool compares(Node a,Node b){
    if(a.deadline==b.deadline){
        return a.cnt>b.cnt;
    }
    return a.deadline<b.deadline;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        long long a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),compares);

   long long ans = 0;

    // 오름차순
    priority_queue<long long,vector<long long>,greater<long long>>pq;

    for(int i=0;i<N;i++){
        pq.push(v[i].cnt);
        // 현재 턴에서 컵라면을 받았을때 데드라인 보다 더 크다면 안됨
        if(v[i].deadline<pq.size()){
            pq.pop();
        }
    }


    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }

    

    cout<<ans<<"\n";
   
}