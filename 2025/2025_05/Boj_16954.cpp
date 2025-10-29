#include<bits/stdc++.h>
using namespace std;
char arr[8][8];
int dx[9]={0,0,0,-1,1,-1,-1,1,1};
int dy[9]={0,-1,1,0,0,-1,1,1,-1};
set<pair<int,int>>wallq;
set<pair<int,int>>wookq;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='#'){
                wallq.insert({i,j});
            }
        }
    }

    wookq.insert({7,0});
    bool arrived = false;

    while(!wookq.empty()){
        // 욱제 이동

        // 다른 큐를 둬야하는 이유 => visited안쓰기때문에, 현재 안전한 칸도 다음에 위험해질수 있음
        set<pair<int,int>>nextq;
        for(auto[x,y]:wookq){
                if(arr[x][y]=='#'){
                    continue;
                }
                if(x==0&&y==7){
                    cout<<1<<endl;
                    return 0;
                }
                for(int i=0;i<9;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx>=0&&nx<8&&ny>=0&&ny<8){
                        if(arr[nx][ny]!='#'){
                            nextq.insert({nx,ny});
                        }
                    }
                }
        }
        set<pair<int,int>>nextwallq;
        char narr[8][8];
        memset(narr,'.',sizeof(narr));
        for(auto[x,y]:wallq){
            arr[x][y]='.';
            if(x+1<8){
                narr[x+1][y]='#';
                nextwallq.insert({x+1,y});
            }
        }
        memcpy(arr,narr,sizeof(arr));
        wallq=nextwallq;
   

        set<pair<int,int>>filtered;
        for(auto pos:nextq){
            if(arr[pos.first][pos.second]!='#'){
                filtered.insert({pos.first,pos.second});
            }
        }
        wookq=filtered;
     
    }
    cout<<0<<endl;


}