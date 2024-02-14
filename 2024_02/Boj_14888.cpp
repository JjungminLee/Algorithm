#include <bits/stdc++.h>

using namespace std;

int n;
int arr[12];

vector<int>calV;
vector<bool>visits;
int cnt;
int maxNum = INT_MIN;
int minNum = INT_MAX;
// 벡터에 연산자를 넣기

void dfs(int depth,vector<int>v){
  
    if(depth==cnt){
     

        int ans=arr[0];
        for(int i=1;i<n;i++){
            //덧셈
           if(v[i-1]==0){
            ans+=arr[i];

           }
           //뺄셈
           else if(v[i-1]==1){
            ans-=arr[i];

           }

           //곱셈
           else if(v[i-1]==2){
            ans*=arr[i];

           }
           //나눗셈
           else if(v[i-1]==3){
            ans/=arr[i];

           }

        }
        minNum=min(minNum,ans);
        maxNum=max(maxNum,ans);

        return;

    }
    else{
        for(int i=0;i<calV.size();i++){
            if(visits[i]==false){
                visits[i]=true;
                v.push_back(calV[i]);
                dfs(depth+1,v);
                v.pop_back();
                visits[i]=false;
            }

        }
    }

}
int main(){
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cnt=n-1;
    for(int i=0;i<4;i++){
        int num;
        cin>>num;
        for(int j=1;j<=num;j++){
            calV.push_back(i);

        }
    }
   
    vector<int>v;
    for(int i=0;i<calV.size();i++){
        visits.push_back(false);
    }
    
    dfs(0,v);

   
    cout<<maxNum<<endl;
    cout<<minNum<<endl;

}