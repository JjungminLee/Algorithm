#include <bits/stdc++.h>

using namespace std;

int arr[14];
int lotto[6];
bool visited[51];
int k;

void dfs(int idx,int depth){

    if(depth==6){
        for(int i=0;i<6;i++){
            cout<<lotto[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    for(int i=idx;i<k;i++){
        if(visited[arr[i]]==false){
            visited[arr[i]]=true;
            lotto[depth]=arr[i];
            dfs(i+1,depth+1); //현재 인덱스 이후부터 탐색해도 됨!
            visited[arr[i]]=false;
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
        memset(visited, false, sizeof(visited));
    }

}