#include <bits/stdc++.h>

using namespace std;
int N;
map<string, int> m;
vector<pair<string,int>>v;

bool compare(pair<string,int> a, pair<string,int> b){
    if(a.second==b.second){
        return a.first<b.first;
        
    }
    
    return a.second>b.second;

}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;

        if (m.find(str) == m.end()) {
	        m.insert({str,1});
        }
        else{
            for (auto iter = m.begin() ; iter !=  m.end(); iter++)
            {
                if(iter->first==str){
                    iter->second+=1;

                }
            
            }

        }

    }
    
    for (auto iter = m.begin() ; iter !=  m.end(); iter++)
    { 
        v.push_back({iter->first,iter->second});
    }
    sort(v.begin(),v.end(),compare);
    cout<<v[0].first<<endl;


}