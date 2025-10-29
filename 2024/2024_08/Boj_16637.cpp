#include <bits/stdc++.h>
using namespace std;

int n;
int ans = INT_MIN;
string input;

int cal(int a,int b, char op){
    if(op=='+'){
        return a+b;
    }else if(op=='*'){
        return a*b;
    }else if(op=='-'){
        return a-b;
    }
    return a;

}
// dfs 느낌으로
void recursive(int idx,int cur){
    if(idx>n-1){
         ans=max(ans,cur);
         return;
    }
    char oper;
    // 일관성주기
    if(idx==0){
        oper='+';
    }else{
        oper=input[idx-1];
    }
    // 괄호 추가하는 경우
    if(idx+2<n){
        int num=cal(input[idx]-'0',input[idx+2]-'0',input[idx+1]);
        // 어차피 다음에는 괄호 아니니까 cal해줘야
        recursive(idx+4,cal(cur,num,oper));
    }
    recursive(idx+2,cal(cur,input[idx]-'0',oper));
}


int main() {
    cin >> n;
    cin >> input;
    recursive(0,0);
    cout<<ans<<endl;
    return 0;
}
