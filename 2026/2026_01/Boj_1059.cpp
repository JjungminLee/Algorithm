#include<bits/stdc++.h>

using namespace std;

int L;
int n;
vector<int>s;

int startNum;
int endNum = INT_MAX;
int ans;

int main(){
    cin>>L;
    for(int i=0;i<L;i++){
        int num;
        cin>>num;
        s.push_back(num);
    }
    cin>>n;
    sort(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]==n){
            cout<<0<<"\n";
            return 0;
        }
    }

    for(int i=0;i<s.size();i++){
        if(s[i]<n){
            startNum=max(startNum,s[i]);
        }
        if(s[i]>n){
            endNum = min(endNum,s[i]);
        }
    }
    
    ans = (n-startNum)*(endNum-n)-1;
    if(ans<0){
        cout<<0<<"\n";
    }else{
        cout<<ans<<"\n";
    }
}