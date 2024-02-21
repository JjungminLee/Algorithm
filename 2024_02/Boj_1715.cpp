#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> v;
int ans;

int main(){
    cin>>N;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        pq.push(num);
    }
    while(pq.size()>=2){
        int num1=pq.top();

        pq.pop();
        int num2=pq.top();

        pq.pop();
        int cnt=num1+num2;
        ans+=cnt;
        pq.push(cnt);
    }
    cout<<ans<<endl;


}