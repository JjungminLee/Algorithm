#include<bits/stdc++.h>
using namespace std;

int n;
vector<string>v;
map<string,int>mp;

int cnt=0;
bool compares(string a,string b){
    return a.size()<b.size();
}
int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    sort(v.begin(),v.end(),compares);

    for(int i=0;i<v.size();i++){
        bool isPrefix = false;
        for(int j=i+1;j<v.size();j++){
            if(v[j].substr(0,v[i].size())==v[i]){
                isPrefix=true;
                break;
            }

        }
        if(isPrefix){
            cnt++;    
        }
    }
    cout<<n-cnt<<"\n";

}