#include<bits/stdc++.h>

using namespace std;

int n;
// 내구도, 무게
vector<pair<int,int>>v;
bool isVisited[10];
int ans;

void backTracking(int idx,int cnt){
    if(idx==n){
        ans=max(ans,cnt);
        return;
    }

    // 손에 든 계란이 깨졌거나
    if(v[idx].first<=0){
        backTracking(idx+1,cnt);
        return;
    }

    int cs = v[idx].first;
    int cw = v[idx].second;

    //가장 왼쪽의 계란을 들어야하므로 0부터 시작
    bool hit=false;
    for(int i=0;i<n;i++){
        //자기 자신 깨지 않기
        if(i==idx) continue;

        // 이미 내구도가 0이하이면 깨지 않기
        if(v[i].first<=0) continue;

        int ns = v[i].first;
        int nw = v[i].second;
        int cur = cs-nw;
        int next = ns-cw;
        int tcnt=0;

        hit = true;

        v[idx].first-=nw;
        v[i].first-=cw;
        if(cs>0&&v[idx].first<=0) tcnt++;
        if(ns>0&&v[i].first<=0) tcnt++;
        backTracking(idx+1,cnt+tcnt);
        v[idx].first+=nw;
        v[i].first+=cw;
    }

    // 깨지지 않은 다른 계란이 없으면  넘길 것(깨지지 않은 계란이 없다는건 hit=false임)
    if(!hit){
        backTracking(idx+1,cnt);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int s,w;
        cin>>s>>w;
        v.push_back({s,w});
    }

    backTracking(0,0);
    cout<<ans<<"\n";

}