#include<bits/stdc++.h>

using namespace std;

long long l;
long long r;
int ans ;

int find8Count(string lstr,string rstr){
    int size = lstr.size();
    int cnt = 0;

    for(int i=0;i<size;i++){
        
        if(lstr[i]=='8'&&rstr[i]=='8'){
            cnt++;
        }
        if(lstr[i]!=rstr[i]){
            break;
        }
    }
    return cnt;
}

int main(){
    cin>>l>>r;
    string lstr = to_string(l);
    string rstr = to_string(r);
    while(lstr.size()!=rstr.size()){
        string tempstr = "0";
        for(int i=0;i<lstr.size();i++){
            tempstr+=lstr[i];
        }
        lstr=tempstr;
    }
    ans = find8Count(lstr,rstr);

    cout<<ans<<"\n";

}