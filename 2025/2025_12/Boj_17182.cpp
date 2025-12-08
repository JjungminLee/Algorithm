#include<bits/stdc++.h>

using namespace std;
int arr[15][15];
int visited[15][15];
int n,k;
int ans=INT_MAX;

void backtracking(int idx, vector<bool>v,int sum){
    int boolCnt = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]){
            boolCnt++;
        }
    }
    if(boolCnt==n){
        ans = min(sum,ans);
        return;
    }
    for(int i=0;i<n;i++){
        if(i==idx) continue;
        if(!v[i]){
            v[i]=true;
            backtracking(i,v,sum+visited[idx][i]);
            v[i]=false;
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            visited[i][j] = INT_MAX;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][k]+arr[k][j]<visited[i][j]){
                    visited[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }

    vector<bool>v(n);
    v[k]=true;
    for(int i=0;i<n;i++){
        backtracking(k,v,visited[k][i]);
    }
    cout<<ans<<"\n";
    

}