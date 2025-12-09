#include<bits/stdc++.h>

using namespace std;
vector<string>v;
int n;

int countNum(string a){
    int cur = 0 ;
    for(int i=0;i<a.size();i++){
        if(a[i]>='A'&&a[i]<='Z') continue;
        int num = a[i]-'0';
        if(num>=0&&num<=9){
            cur+=num;
        }
    }
    return cur;
}

bool comparators(string a,string b){
    if(a.size()==b.size()){
        int acnt = countNum(a);
        int bcnt = countNum(b);
        if(acnt==bcnt){
            for(int i=0;i<a.size();i++){
                int anum = a[i]-'0';
                int bnum = b[i]-'0';

                if(0<=anum&&anum<=9){
                    if(0<=bnum&&bnum<=9){
                        if(bnum==anum) continue;
                        return anum < bnum;
                    }else{
                        // a가 숫자, b가 문자
                        return true;
                    }
                }else{
                    // a가 문자 b가 숫자
                    if(0<=bnum&&bnum<=9){
                        return false;
                    }else{
                        // a가 문자 b가 문자
                        if(a[i]==b[i]) continue;
                        return a[i]<b[i];
                    }
                }
               
                return a[i]>b[i];
            }
        }
        return acnt<bcnt;
    }
    return a.size()<b.size();
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    sort(v.begin(),v.end(),comparators);
    for(int i=0;i<n;i++){
        cout<<v[i]<<"\n";
    }

}