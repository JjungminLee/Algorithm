#include <bits/stdc++.h>

using namespace std;
int N;
vector<string> v;
int arr[26];


int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        int len = str.length();
        int target=pow(10,len-1);
        
        for(int j=0;j<len;j++){
        
            arr[str[j]-65]+=target;
            target/=10;
        }
        
        

    }
    int idx=9;
    int ans=0;
  
    //내림차순
    sort(arr,arr+26,greater<int>());
    for(int i=0;i<26;i++){
      
        arr[i]*=idx;
        idx--;
        ans+=arr[i];

    }
    cout<<ans<<endl;
   
}