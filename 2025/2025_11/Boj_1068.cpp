#include<bits/stdc++.h>

using namespace std;

int n,delNode;
int parent[51];
vector<int> children[51];
bool delNodes[51];
int ans;

// dfs로 삭제해야
void dfs(int node){
    delNodes[node]=true;
    for(int child:children[node]){
        dfs(child);
    }
}

//dfs로 리프 노드 찾아야

int dfs2(int node){
    if(delNodes[node]) return 0;
    bool hasChild = false;
    int leafCnt = 0;
    for(int child:children[node]){
        if(!delNodes[child]){
            hasChild = true;
            leafCnt +=dfs2(child);
        }
    }
    // 자식이 하나도 없으면 리프노드이기에 1반환 자식없으면 0 반환 아님!!
    return hasChild ? leafCnt:1;
}

int main(){
    cin>>n;
    int root = -1;
    for(int i=0;i<n;i++){
        cin>>parent[i];
        if(parent[i]==-1){
            root=i;
        }else{
            children[parent[i]].push_back(i);
        }
    }

    cin>>delNode;
    dfs(delNode);
    cout<<dfs2(root)<<"\n";

}