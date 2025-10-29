#include<bits/stdc++.h>

using namespace std;

#define MAX (600)

int N;
int maps[MAX][MAX];
int w[MAX];
int parents[MAX];

struct Edge{
    int u;
    int v;
    int cost;

};

bool compares(Edge a,Edge b){
    return a.cost<b.cost;
}

int finds(int num){
    if(parents[num]==num){
        return num;
    }
    return parents[num]=finds(parents[num]);
}

bool unions(int a,int b){
    int pa =finds(parents[a]);
    int pb = finds(parents[b]);
    if(pa==pb) return false;
    if(pa<pb){
        parents[pb]=pa;
    }else{
        parents[pa]=pb;
    }
    return true; 
}

int main(){
    cin>>N;

    for(int i=1;i<=N;i++){
        cin>>w[i];
    }

    vector<Edge>edges;

    for(int i=1;i<=N;i++){
        edges.push_back({0,i,w[i]});
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int num;
            cin>>num;
            if(i<j){
                edges.push_back({i,j,num});
            }
        }
    }

    sort(edges.begin(),edges.end(),compares);

    for(int i=0;i<=N;i++){
        parents[i]=i;
    }
    
    int answer = 0;
    int cnt = 0;
    
    for(int i=0;i<edges.size();i++){
        Edge e = edges[i];
        if(unions(e.u,e.v)){
            answer+=e.cost;
            cnt++;
            if(cnt==N){
                break;
            }
        }
    }

    cout<<answer<<"\n";

}