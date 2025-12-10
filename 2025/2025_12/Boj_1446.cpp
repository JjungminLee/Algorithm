#include<bits/stdc++.h>

using namespace std;

int dp[10005];
int n;
int d;
struct Node{
    int s,e,d;
};
vector<Node>v;

int main(){
    cin>>n;
    cin>>d;

    for(int i=0;i<n;i++){
        int s,e,dist;
        cin>>s>>e>>dist;
        v.push_back({s,e,dist});
    }

    for(int i=0;i<=d;i++){
        dp[i]=i;
    }


    for(int i=1;i<=d;i++){
        for(int j=0;j<n;j++){
            int cs = v[j].s;
            int ce = v[j].e;
            int cd = v[j].d;
            if(i==ce){
                dp[i]=min(dp[i],dp[cs]+cd);
            }else if(i>ce){
                dp[i]=min(dp[i],dp[ce]+i-ce);
            }
        }
    }

    cout<<dp[d]<<endl;



}