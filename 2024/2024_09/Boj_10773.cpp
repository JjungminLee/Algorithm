#include<bits/stdc++.h>
using namespace std;
int k;
vector<int>v;
int main(){
    cin>>k;
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        if(num==0){
            v.erase(v.end()-1);
        }else{
            v.push_back(num);
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++){
        ans+=v[i];
    }
    cout<<ans<<endl;

    
}