#include<bits/stdc++.h>
using namespace std;
int N;
struct Node{
    long long deadline;
    long long cnt;
};


struct cmp{
    bool operator()(Node a,Node b){
        if(a.deadline==b.deadline){
            return a.cnt<b.cnt;
        }
        return a.deadline>b.deadline;  
    }
};

int main(){
    cin>>N;
    priority_queue<Node,vector<Node>,cmp>pq;
    for(int i=0;i<N;i++){
        long long a,b;
        cin>>a>>b;
        pq.push({a,b});
    }

    int times = 0;
    int ans = 0;

    while(!pq.empty()){
        Node cur = pq.top();
        //cout<<"deadline "<<cur.deadline<<"cnt "<<cur.cnt<<endl;
        pq.pop();
        if(cur.deadline>times){
            times++;
            ans+=cur.cnt;
        }
    }
    cout<<ans<<endl;
}