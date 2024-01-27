#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<pair<int,int>,int>> v;


int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int weight,height;
        cin>>weight>>height;
        v.push_back({{weight,height},0});;
      
    }
    for(int i=0;i<N;i++){
        int cnt=0;
        for(int j=0;j<N;j++){
           if(i==j){
                continue;
           }else{
             if(v[i].first.first<v[j].first.first&& v[i].first.second<v[j].first.second){
                cnt++;

             }
           }
        }
        v[i].second=cnt+1;
    }

    for(int i=0;i<N;i++){
   
        cout<<v[i].second<<endl;
    }

  
 
}