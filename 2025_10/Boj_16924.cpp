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
        while(nx>=0&&nx<N&&ny>=0&&ny<M&&maps[nx][ny]=='*'){
            tmp[i]++;
            nx+=dx[i];
            ny+=dy[i];
        }
    }
    int minLen=tmp[0];

    for(int i=1;i<4;i++){
        minLen=min(tmp[i],minLen);
    }

    return minLen;
}


int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>maps[i][j];
        }
    }

    int marked[105][105]={0,};

    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            if(maps[i][j]=='*'){
                int len = findLen(i,j);
                if(len<=0) continue;
                v.push_back({i+1,j+1,len});
                marked[i][j]=1;
                for(int k=1;k<=len;k++){
                    marked[i-k][j]=1;
                    marked[i+k][j]=1;
                    marked[i][j-k]=1;
                    marked[i][j+k]=1;
                }
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(maps[i][j]=='*'&&!marked[i][j]){
                cout<<-1<<"\n";
                return 0;
            }
        }
    }

    if(v.size()==0){
        cout<<-1<<"\n";
        return 0;
    }

    int size = 0;
    for(Node item:v){
        size+=item.len;
    }

    cout<<size<<"\n";

    for(Node item:v){
        for(int s=1;s<=item.len;s++){
            cout<<item.x<<" "<<item.y<<" "<<s<<"\n";
        }
    }


}