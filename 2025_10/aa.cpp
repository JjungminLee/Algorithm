#include<bits/stdc++.h>
using namespace std;

int N,M;
char maps[105][105];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct Node{
    int x;
    int y;
    int len;
};

vector<Node> v;

int findLen(int x,int y){
   vector<int>tmp(4);
    
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        while(nx>=0&&nx<N&&ny>=0&&ny<M){
            if(maps[nx][ny]=='*'){
                tmp[i]++;
            }
            nx+=dx[i];
            ny+=dy[i];
        }
    }
    int minLen=INT_MAX;

    for(int i=0;i<4;i++){
        minLen=min(tmp[i],minLen);
    }

    return minLen;
}

bool findValid(int x,int y){
   vector<int>tmp(4);
    
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        while(nx>=0&&nx<N&&ny>=0&&ny<M&&maps[nx][ny]!='*'){
            tmp[i]++;
            nx+=dx[i];
            ny+=dy[i];
        }
    }

    int std = tmp[0];

    for(int i=1;i<4;i++){
        if(std!=tmp[i]){
            return false;
        }
    }

    return true;
}


int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>maps[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(maps[i][j]=='*'){
                int len = findLen(i,j);
                if(len==INT_MAX||len==0) continue;
                v.push_back({i+1,j+1,len});
            }
        }
    }

    if(v.size()==0){
        cout<<-1<<"\n";
        return 0;
    }

    if(v.size()==1){
        if(!findValid(v[0].x,v[0].y)){
            cout<<-1<<"\n";
            return 0;
        }
    }
    
    int size = 0;
    

    for(int i=0;i<v.size();i++){
        for(int j=1;j<=v[i].len;j++){
            size++;
        }
    }

    cout<<size<<"\n";

    for(int i=0;i<v.size();i++){
        for(int j=1;j<=v[i].len;j++){
            
            cout<<v[i].x<<" "<<v[i].y<<" "<<j<<"\n";
        }
    }



}