#include <bits/stdc++.h>

using namespace std;

vector<int>v;
int x;
int cnt;
int ans =INT_MAX;
int arr[10];
bool visits[7];
int MAX = 2147483647;

void dfs(int depth){
    if(depth==cnt){
        string str="";
        for(int i=0;i<depth;i++){
            str+=to_string(arr[i]);
        }
        int num = stoi(str);
        if(num<ans&&num>x){
            ans=num;
        }
        return;

    }
    for(int i=0;i<cnt;i++){
        if(visits[i]==false){
            arr[depth]=v[i];
            visits[i]=true;
            dfs(depth+1);
            visits[i]=false;

        }
    }
}
int main(){
    cin>>x;
    string str = to_string(x);
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        v.push_back(ch-'0');
    }
    sort(v.begin(),v.end());
    cnt= v.size();
    dfs(0);
    if(ans==MAX){
        cout<<0<<endl;
    }else{
        cout<<ans<<endl;
    }
}