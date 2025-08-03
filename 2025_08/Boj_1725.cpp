#include<bits/stdc++.h>
using namespace std;
int n;
long long v[100002];
// 높이 위치
stack<pair<long long,int>>stk;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    v[n+1]=0;
    long long maxAns=0;

    // 낮아지는 시점
    for(int i=1;i<=n+1;i++){
        int lastDir = i;
        while(!stk.empty()){
            auto cur = stk.top();
            if(cur.first<=v[i]){
                break;
            }else{
                long long area = cur.first*(i-cur.second);
                maxAns = max(area,maxAns);
                lastDir = cur.second;
                stk.pop();
            }
        }
        stk.push({v[i],lastDir});
        
    }
    cout<<maxAns<<endl;

}