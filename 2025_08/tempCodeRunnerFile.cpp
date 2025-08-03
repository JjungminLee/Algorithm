#include<bits/stdc++.h>
using namespace std;
int n;
long long v[1000001];
// 높이 위치
stack<pair<int,int>>stk;
long long ans[1000001];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    // 낮아지는 시점
    for(int i=1;i<=n;i++){
        if(stk.empty()){
            stk.push({v[i],i});
        }else{
            int lastDir = 0;
            while(!stk.empty()){
                auto cur = stk.top();
                if(cur.first<=v[i]){
                    stk.push({v[i],i});
                    break;
                }else{
                    ans[i] = cur.first*(i-cur.second);
                    lastDir = cur.second;
                    stk.pop();
                }
            }
            stk.push({v[i],lastDir});
        }
        
    }
    long long maxAns=0;
    for(int i=1;i<=n+1;i++){
        if(ans[i]>maxAns){
            maxAns=ans[i];
        }
    }
    cout<<maxAns<<endl;

}