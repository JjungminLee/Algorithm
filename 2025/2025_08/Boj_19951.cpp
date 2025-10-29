#include<bits/stdc++.h>
using namespace std;

int n,m;
int heights[100002];
int diff[100002];
long long prefixSum[100002];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>heights[i];
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        diff[a]+=c;
        diff[b+1]+=(c*-1);
    }

    long long cur = 0;
    for(int i=1;i<=n;i++){
        cur+=diff[i];
        prefixSum[i] = cur;
    }
    for(int i=1;i<=n;i++){
        cout<<heights[i]+prefixSum[i]<<" ";
    }
    cout<<endl;

}