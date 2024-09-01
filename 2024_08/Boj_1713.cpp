#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int arr[10001];
vector<int>v;
unordered_map<int,int>timestamp;
unordered_map<int,int>recom;
int main(){

    cin>>n;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    int idx=0;
    int time=0;
    while(idx<m){
        int student=arr[idx];
        time++;
        if(v.size()==n){
            sort(v.begin(),v.end(),[&](int a,int b){
                if(recom[a]==recom[b]){
                    return timestamp[a]<timestamp[b];
                }
                return recom[a]<recom[b];
            });
            // 끝까지 찾았는데 없음
            if(find(v.begin(),v.end(),student)==v.end()){
                int remove=v.front();
                v.erase(v.begin());
                recom[remove]=0;
                timestamp.erase(remove);
                v.push_back(student);
                recom[student]=1;
                timestamp[student]=time;
            }else{
                recom[student]++;
            }

        }else{
            if(find(v.begin(),v.end(),student)==v.end()){
                
                v.push_back(student);
                recom[student]=1;
                timestamp[student]=time;
            }else{
                recom[student]++;
            }

        }
        idx++;

    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
