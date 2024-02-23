#include <bits/stdc++.h>

using namespace std;

string str;
string target;
string strTemp="";
int tLen=0;
int main(){
    cin>>str;
    cin>>target;
    tLen = target.length();
    stack<char>stack;
    reverse(target.begin(),target.end());//4c
   
    for(int i=0;i<str.length();i++){
  
        stack.push(str[i]);
   
        if(stack.size()>=tLen&&stack.top()==target[0]){
            string checkStr="";
            for(int i=0;i<tLen;i++){
                checkStr+=stack.top();
                stack.pop();
            }
            // 4c
            if(checkStr!=target){
                for(int j=checkStr.length()-1;j>=0;j--){
                    stack.push(checkStr[j]);
                }

            }
        }
    }
    string ans="";
    while(!stack.empty()){
        ans+=stack.top();
        stack.pop();
    }
    if(ans.length()>0){
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }else{
        cout<<"FRULA"<<endl;
    }
   
    
}