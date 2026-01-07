#include<bits/stdc++.h>

using namespace std;

int n;
int visitCnt;

struct Node{
    int start;
    int end;
    int idx;
};
bool compares(Node a,Node b){
    return a.start<b.start;
}

int ans ;
vector<Node>v;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int s,e,idx;
        cin>>idx>>s>>e;
        v.push_back({s,e,idx});
    }
    priority_queue<int,vector<int>,greater<>>pq;

    sort(v.begin(),v.end(),compares);

    pq.push(v[0].end);


    for(int i=1;i<n;i++){
        // 겹치는 경우 이전의 end값은 제거하고
        if(!pq.empty()&&pq.top()<=v[i].start){
            pq.pop();
        }
        // 새로운 end값으로 푸쉬(갱신)
        pq.push(v[i].end);
    }

    cout<<pq.size()<<"\n";

}