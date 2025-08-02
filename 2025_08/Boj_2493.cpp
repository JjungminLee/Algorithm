#include<bits/stdc++.h>
using namespace std;

int n;
int arr[500001];
stack<pair<long long,int>>stk;
int ans[500001];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
			cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
		while(!stk.empty()){
			auto cur = stk.top();
			if(cur.first<=arr[i]){
					ans[cur.second]=i+1;
					stk.pop();
			}else{
				stk.push({arr[i],i});
				break;
			}
		}
		stk.push({arr[i],i});
    }
    for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
    }
    cout<<endl;

}