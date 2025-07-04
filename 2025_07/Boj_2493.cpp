#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    stack<pair<long long, long long>> stk; // 높이, 인덱스
    vector<long long> answer(n);
    vector<long long> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
        while(!stk.empty()&&stk.top().first<height[i]){
            stk.pop();
        }
        if(!stk.empty()){
            answer[i]=stk.top().second+1;
        }
        stk.push({height[i],i});
    }
  
    for(int i:answer){
        cout<<i<<" ";
    }
    cout<<endl;
  

}