#include<bits/stdc++.h>
using namespace std;

int n;
int ans;
stack<int>stk;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        while(!stk.empty()&&stk.top()>y){
            stk.pop();
        }
        if(stk.empty()||stk.top()<y){
            stk.push(y);
            if(y!=0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    

}