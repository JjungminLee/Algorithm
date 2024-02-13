#include <bits/stdc++.h>

using namespace std;

stack<int>s[7];
int n,p;
int main(){
    cin>>n>>p;
    int ans=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(s[a].empty()){
            s[a].push(b);
            ans++;
        }else if(s[a].top()<b){
            s[a].push(b);
            ans++;
        }else if(s[a].top()>b){
            while(s[a].top()>b){
                s[a].pop();
                ans++;
                // 계속 빼다가 비게 되는 경우
                if(s[a].empty()){
                    s[a].push(b);
                    ans++;
                }
            }
            // 애는 반복문에 넣어줄 필요가 없음 어차피 top이 b보다 크면 그냥 푸쉬하고 ans++하고 끝내야!
            if(s[a].top()<b){
                s[a].push(b);
                ans++;
            }
        }
    }
    cout<<ans<<endl;

}