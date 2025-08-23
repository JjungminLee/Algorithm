#include<bits/stdc++.h>
using namespace std;

int n,m;
int parents[10001];
int sp,ep;

struct Node{
    long long cnt;
    int start;
    int end;
};

vector<Node>v;

bool compares(Node a,Node b){
    return a.cnt>b.cnt;
}

int find(int num){
    if(num==parents[num]){
       return num;
    }
    return parents[num]=find(parents[num]);
}
void unions(int a,int b){
    if(a<b){
        parents[b]=a;
    }else{
        parents[a]=b;
    }

}
int main(){

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({c,a,b});
    }
    cin>>sp>>ep;
    for(int i=1;i<=n;i++){
        parents[i]=i;
    }
    sort(v.begin(),v.end(),compares);
    for(int i=0;i<v.size();i++){
        long long cnt = v[i].cnt;
        int start = find(v[i].start);
        int end = find(v[i].end);
        
        if(start!=end){
            unions(start,end);
        }

        if(find(sp)==find(ep)){
            cout<<cnt<<"\n";
            return 0;
        }
    }
}