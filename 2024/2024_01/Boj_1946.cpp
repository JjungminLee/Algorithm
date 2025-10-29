#include <bits/stdc++.h>

using namespace std;

int T;
int N;
vector<pair<int,int>> v;
int cmp(pair<int,int> a, pair<int,int>b){
    if(a.first>b.first){
        return false;
    }
    return true;
}

int main(){

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        int cnt=1;
        v.clear();
        for(int j=0;j<N;j++){
            int a,b;
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end(),cmp);
        int std =v[0].second;
        for(int j=1;j<N;j++){
      
            if(std>v[j].second){
                std=v[j].second;
           
                cnt++;
            }

        }
        cout<<cnt<<endl;
    }

    


    
}