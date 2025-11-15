#include<bits/stdc++.h>

using namespace std;
int n;
int delNode;
int parents[51];
int root;
vector<int>children[51];
bool delNodes[51];

void dfsDel(int num){
    delNodes[num]=true;
    for(int child:children[num]){
        dfsDel(child);
    }
}

int dfsCheckLeaf(int node){
    if(delNodes[node]) return 0;
    bool hasLeaf = false;
    int leafCnt = 0;
    for(int child:children[node]){
        if(!delNodes[child]){
            hasLeaf = true;
            leafCnt += dfsCheckLeaf(child);
        }
    }
    return hasLeaf?leafCnt:1;
}

int main(){
    cin>>n;
    root = -1;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        parents[i]=m;
        if(m==-1){
            root=i;
        }else{
            children[parents[i]].push_back(i);
        }
    }

    cin>>delNode;
    dfsDel(delNode);
    cout<<dfsCheckLeaf(root)<<"\n";

}