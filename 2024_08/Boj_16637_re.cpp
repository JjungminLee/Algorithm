#include<bits/stdc++.h>
using namespace std;
int n;
string input;
int ans=INT_MIN;
int cal(int a,int b,char oper){
    if(oper=='+'){
        return a+b;
    }else if(oper=='-'){
        return a-b;
    }else if(oper=='*'){
        return a*b;
    }
    return a;
}
void recursive(int idx,int cur){
    if(idx>n-1){
        ans=max(ans,cur);
        return;
    }
    char oper;
    if(idx==0){
        oper='+';
    }else{
        oper=input[idx-1];
    }
    if(idx+2<n){
        int num=cal(input[idx]-'0',input[idx+2]-'0',input[idx+1]);
        // 순서 중요 -> 이전꺼 (oper) 괄호통해 계산한거 순이여야 (만약에 마이너스라면?!)
        recursive(idx+4,cal(cur,num,oper));
    }
    recursive(idx+2,cal(cur,input[idx]-'0',oper));
}
int main(){
    cin>>n;
    cin>>input;
    recursive(0,0);
    cout<<ans<<endl;

}