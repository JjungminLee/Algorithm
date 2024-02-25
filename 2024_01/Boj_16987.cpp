#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int,int>> v;
bool breakEgg[9];
int ans = 0;
void dfs(int pos){
    if(pos==N){
        int cnt =0 ;
        for(int i=0;i<N;i++){
            if(v[i].first<=0){
                cnt++;

            }
        }
        ans=max(ans,cnt);
        return;
    }
   if(v[pos].first<=0){
    dfs(pos+1);
    return;
   }
    bool flag=false;
   // 1부터 끝까지 돌아야함!
   for(int i=0;i<N;i++){
    if(i==pos||v[i].first<=0){
        continue;
    }else{
        flag=true;
        v[i].first-=v[pos].second;
        v[pos].first-=v[i].second;
        dfs(pos+1);
         v[i].first+=v[pos].second;
        v[pos].first+=v[i].second;

    }
   }
   // 현 위치에서는 더이상 깰 수 있는게 없는거
   if(!flag){
    dfs(pos+1);
   }


}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int s;
        int w;
        cin>>s>>w;
        v.push_back({s,w});
    }
    dfs(0);
    cout<<ans<<endl;
}