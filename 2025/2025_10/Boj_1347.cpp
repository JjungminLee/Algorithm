#include<bits/stdc++.h>

using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
int curDir=2;// 남쪽부터 시작
vector<pair<int,int>>v;
char maps[101][101];
int cr;
int cc;
int er=50;
int ec=50;
int sr=50;
int sc=50;

int main(){
    cin>>N;
    cr=50;
    cc=50;
    v.push_back({cr,cc});
    for(int i=0;i<N;i++){
        char dir;
        cin>>dir;
        if(dir=='R'){
            curDir=(curDir+1)%4;
        }else if(dir=='L'){
            curDir=(curDir+3)%4;
        }else if(dir=='F'){
            cr+=dx[curDir];
            cc+=dy[curDir];
            sr=min(sr,cr);
            sc=min(sc,cc);
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