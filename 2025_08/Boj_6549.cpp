#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int n;
        cin>>n;
        if(n==0){
            break;
        }else{
           long long arr[100002]={0,};
           long long maxAns=0;
           stack<pair<long long,int>>stk;
           for(int i=1;i<=n;i++){
            cin>>arr[i];
           }
           for(int i=1;i<=n+1;i++){
                int lastDir = i;
                while(!stk.empty()){
                    auto cur = stk.top();
                    if(cur.first<=arr[i]){
                        break;
                    }else{
                        // 낮아지는 시점에 pop
                        lastDir = cur.second;
                        maxAns = max(maxAns,(i-lastDir)*cur.first);
                        stk.pop();
                    }
                }
                stk.push({arr[i],lastDir});
           }
           cout<<maxAns<<endl;
           
        }
    }

}