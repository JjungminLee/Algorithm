#include<bits/stdc++.h>

using namespace std;

long long l;
long long r;
int ans ;

int find8Count(string lstr,string rstr){
    int size = lstr.size();
    int cnt = 0;

    for(int i=size-1;i>=0;i--){
        if(lstr[i]=='8'&&rstr[i]=='8'){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    cin>>l>>r;
    string lstr = to_string(l);
    string rstr = to_string(r);
    ans = find8Count(lstr,rstr);

    cout<<ans<<"\n";

}