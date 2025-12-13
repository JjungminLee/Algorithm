#include<bits/stdc++.h>

using namespace std;
int firstMinusPos=-1;
vector<string>v;

int main(){
    string str;
    cin>>str;
    string temp="";
    for(int i=0;i<str.size();i++){
        if(str[i]=='-'||str[i]=='+'){
            v.push_back(temp);
            temp="";
            temp+=str[i];
            v.push_back(temp);
            temp="";
        }else{
            temp+=str[i];
        }
    }
    if(temp!=""){
        v.push_back(temp);
    }

    for(int i=v.size()-1;i>=0;i--){
        if(v[i]=="-"){
            firstMinusPos=i;
        }
    }
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<"\n";
    // firstMinusPos이전까지 + 계산 끝내기

    int sum = 0;

    if(firstMinusPos==-1){
        for(int i=0;i<v.size();i++){
            if(v[i]!="-"&&v[i]!="+"){
                int num = stoi(v[i]);
                sum+=num;
            }
        }
        cout<<sum<<"\n";
        return 0;
        
    }

    for(int i=firstMinusPos+1;i<v.size();i++){
        if(v[i]!="-"&&v[i]!="+"){
            int num = stoi(v[i]);
            sum-=num;
        }
    }
    sum+=stoi(v[0]);
    for(int i=1;i<firstMinusPos-1;i++){
        if(v[i]=="-"){
            sum-=stoi(v[i+1]);
        }else if(v[i]=="+"){
            sum+=stoi(v[i+1]);
        }
    }
    cout<<sum<<"\n";
}