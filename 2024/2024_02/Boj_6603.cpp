#include <bits/stdc++.h>

using namespace std;

int k;
int arr[14];
int lotto[14];
bool visits[50];

void dfs(int idx,int depth){
    if(depth==6){
        for(int i=0;i<6;i++){
            cout<<lotto[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=idx;i<k;i++){
        if(visits[arr[i]]==false){
            visits[arr[i]]=true;
            // i는 동적으로 변하니까 depth여야!
            lotto[depth]=arr[i];
            dfs(i+1,depth+1);
            visits[arr[i]]=false;
        }
    }
    

}

int main(){
    
    while(true){
        cin>>k;
        if(k==0){
            break;
        }
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        dfs(0,0);
        cout<<endl;
    }

}