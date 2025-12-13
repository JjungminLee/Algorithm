#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<string,long long>>v;
int maxSongs;
int minGuitars=INT_MAX;

int findOneCount(long long bit){
    int cnt = 0;
    while(bit>=1){
        if(bit%2==1) cnt++;
        bit/=2;
    }
    if(bit==1){
        cnt++;
    }

    return cnt;
}

void backtracking(int idx,long long bit,int cnt){
    int songCnt = findOneCount(bit);
    //cout<<"bit "<<bit<<"songCnt "<<songCnt<<endl;
    if(songCnt>maxSongs){
        maxSongs = songCnt;
        minGuitars = cnt;
    }else if(songCnt == maxSongs){
        if(minGuitars>cnt){
            minGuitars = cnt;
        }
    }

    for(int i=idx;i<n;i++){
        backtracking(i+1,bit|v[i].second,cnt+1);
        backtracking(i+1,bit,cnt);
    }
}

int main(){

    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        string bitStr;
        cin>>str>>bitStr;
        long long bit = 0;
        for(int i=0;i<m;i++){
            bit<<=1; // 비트를 왼쪽으로 한칸 밀기
            if(bitStr[i]=='Y'){
                bit|=1;
            }
        }
        v.push_back({str,bit});
    }
   
    backtracking(0,0,0);

    if(minGuitars==0||minGuitars==INT_MAX){
        cout<<-1<<"\n";
    }else{
        cout<<minGuitars<<"\n";
    }
}