#include<bits/stdc++.h>

using namespace std;

// 상 우 하 좌
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

int N;
int curDir = 2; // 하 방향 부터 시작
char maps[101][101];
int sr=50;
int sc=50;
int er=50;
int ec=50;
int cr=50;
int cc=50;

vector<pair<int,int>>v;

int main(){

    cin>>N;
    v.push_back({cr,cc});
    for(int i=0;i<N;i++){
        char ch;
        cin>>ch;
        if(ch=='L'){
            curDir = (curDir+3)%4;

        }else if(ch=='R'){
            curDir = (curDir+1)%4;

        }else if(ch=='F'){
            cr+=dr[curDir];
            cc+=dc[curDir];
            sr=min(cr,sr);
            sc=min(cc,sc);
            er=max(er,cr);
            ec=max(ec,cc);
            v.push_back({cr,cc});
        }

    }

    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            maps[i][j]='#';
        }
    }

    for(int i=0;i<v.size();i++){
        int r = v[i].first;
        int c = v[i].second;
        maps[r][c]='.';
    }

    for(int i=sr;i<=er;i++){
        for(int j=sc;j<=ec;j++){
            cout<<maps[i][j];
        }
        cout<<"\n";
    }

}