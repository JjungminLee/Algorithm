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
        // 일단 넣고
        pq.push(v[i].cnt);
        // 데드라인 초과하면
        if(v[i].deadline<pq.size()){
            pq.pop(); // 컵라면 하나 버림
        }
    }


    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }

    

    cout<<ans<<"\n";
   
}