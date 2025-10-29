#include <bits/stdc++.h>

using namespace std;

int n;


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        queue<pair<int,int>>q;
        priority_queue<int>pq;
        vector<pair<int,int>>v;
        int a,b;
        cin>>a>>b;
        int cnt=1;

        // 우선순위 큐에 하나, 그냥 큐 하나
        // 우선순위 큐에는 우선순위 높은애 순서대로 넣고
        // 그냥큐에는 우선순위값, 인덱스값
        for(int j=0;j<a;j++){
            int num;
            cin>>num;
            q.push({num,j});
            pq.push(num);
        }

        while(!q.empty()){
            int num = q.front().first;
            int idx=q.front().second;
            q.pop();
            if(pq.top()==num){
                v.push_back({num,idx});
                pq.pop();
            }else{
                q.push({num,idx});
            }
        }
        for(int i=0;i<v.size();i++){
          if(v[i].second==b){
            break;
          }else{
            cnt++;
          }
        }

        cout<<cnt<<endl;

        
    }

}