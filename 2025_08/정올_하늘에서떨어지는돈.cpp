#include<bits/stdc++.h>
using namespace std;
int n;
int m;
 priority_queue<long long,vector<long long>,greater<long long>>pq;
vector<long long>v;
bool compares(long long a, long long b){
    return a<b;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        long long num;
        cin>>num;
        pq.push(num);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        long long num;
        cin>>num;
        v.push_back(num);
    }
    for(long long ll:v){
        if(!pq.empty()){
            long long cur = pq.top();
            pq.pop();
            pq.push(cur+ll);
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}
