#include<bits/stdc++.h>
using namespace std;

int n,m;
int k;
int arr[51][51];
map<string,int>mp;
int ans;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        mp[str]++;
    }
    cin>>k;
    
    for(auto it=mp.begin();it!=mp.end();it++){
        string str=it->first;
        int tmp=0;

        for(char ch:str){
            if(ch=='0'){
                tmp++;
            }
        }
        if(tmp<=k&&(k-tmp)%2==0){
         
            ans=max(it->second,ans); // it->second임! tmp아님!(tmp는 서로 같은 문자열을 가진 행을 구분 못함)
        }
    }
    cout<<ans<<endl;

}