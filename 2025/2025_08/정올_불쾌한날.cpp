#include<bits/stdc++.h>
using namespace std;

stack<long long> stk;
stack<long long> tempStk;
vector<long long> v;
int n;
long long ans;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        long long num;
        cin>>num;
        v.push_back(num);
    }

    for(int i=0;i<n;i++){
        while(!stk.empty() && v[stk.top()]<=v[i]){
			stk.pop();
        }
        ans+=stk.size();
        stk.push(i);
    }
    cout<<ans<<endl;

}