#include<bits/stdc++.h>

using namespace std;
int N;
int M;
int inDegree[32005];
vector<int> v[32005];
vector<int>ans;

void toplogySort(){
    queue<int>q;
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    // N번 반복하면 모든 노드 한번씩 꺼내게 된 것임
    for(int i=0;i<N;i++){
        // 더이상 진입차수가 0인게 없다
        if(q.empty()){
            return;
        }

        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(int j=0;j<v[cur].size();j++){
            int next = v[cur][j];
            inDegree[next]--;
            if(inDegree[next]==0) q.push(next);
        }
    }

}

int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        inDegree[b]++;
    }
    toplogySort();
    for(int num:ans){
        cout<<num<<" ";
    }
    cout<<"\n";
}