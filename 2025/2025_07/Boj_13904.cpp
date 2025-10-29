#include<bits/stdc++.h>
using namespace std;

int n;
int ans;
vector<int>v;
int main(){
    priority_queue<pair<int,int>>pqScore;
    cin>>n;
    v=vector<int>(1001);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pqScore.push({b,a});
    }
    while(!pqScore.empty()){
        auto curScore = pqScore.top();
      
        pqScore.pop();

            for(int i=curScore.second;i>=1;i--){
                if(v[i]==0){
                    v[i]=curScore.first;
                    break;
                }
            }
        
    }

    for(int i=1;i<=1000;i++){
        ans+=v[i];
    }

    cout<<ans<<endl;
    
}