#include<bits/stdc++.h>

using namespace std;
int R,C;
char maps[30][30];
// 상 하 좌 우
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

bool isInRange(int r,int c){
    if(r>=0&&r<R&&c>=0&&c<C){
        return true;
    }
    return false;
}
int findr;
int findc;
char findChar;

map<char,vector<int>>mp={
    {
        '|',{0,1}
    },{
        '-',{2,3}
    },{
        '+',{0,1,2,3}
    },{
        '1',{1,3}
    },{
        '2',{0,3}
    },{
        '3',{2,0}
    },{
        '4',{1,2}
    }

};
vector<char>nDirs[4];


int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>maps[i][j];
        }
    }

    nDirs[0]={'|','+','2','3'};
    nDirs[1]={'|','+','1','4'};
    nDirs[2]={'-','+','1','2'};
    nDirs[3]={'-','+','4','3'};

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(maps[i][j]=='.') continue;

            bool con[4]={false,};
            for(int dir=0;dir<4;dir++){
                int nr = i+dx[dir];
                int nc = j+dy[dir];
                if(!isInRange(nr,nc))continue;
                char next = maps[nr][nc];
                if(next=='.') continue;

                int opp = dir^1; // qkseoqkdgid

                if(find(mp[next].begin(),mp[next].end(),opp)!=mp[next].end()){
                    con[dir]=true;
                }

                
            }

            if(con[0]&&con[1]&&!con[2]&&!con[3]){
                findChar='|';
            }else if(!con[0]&&!con[1]&&con[2]&&con[3]){
                findChar='-';
            }else if(con[0]&&con[1]&&con[2]&&con[3]){
                findChar='+';
            }else if(con[1]&&con[3]){
                findChar='1';
            }else if(con[0]&&con[3]){
                findChar='2';
            }else if(con[0]&&con[2]){
                findChar='3';
            }else if(con[1]&&con[2]){
                findChar='4';
            }else{
                continue;
            }

            findr=i+1;
            findc=j+1;

        }
    }

    cout<<findr<<" "<<findc<<" "<<findChar<<"\n";

}