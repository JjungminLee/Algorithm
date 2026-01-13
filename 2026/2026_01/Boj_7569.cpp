#include<bits/stdc++.h>

using namespace std;

int m,n,h;

int dx[6]={-1,1,0,0,0,0};
int dy[6]={0,0,-1,1,0,0};
int dz[6]={0,0,0,0,-1,1};

int arr[105][105][105];

int answer;

struct Node{
    int x;
    int y;
    int z;
    int day;
};


int main(){
    cin>>m>>n>>h;

    queue<Node>q;
    int zeroCnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>arr[j][k][i];
                if(arr[j][k][i]==1){
                    q.push({j,k,i,0});
                }else if(arr[j][k][i]==0){
                    zeroCnt++;
                }
            }
        }
    }

    if(zeroCnt==0){
        cout<<0<<"\n";
        return 0;
    }

    while(!q.empty()){
        Node node = q.front();
        q.pop();
        answer=max(answer,node.day);

        for(int i=0;i<6;i++){
            int nx=node.x+dx[i];
            int ny = node.y+dy[i];
            int nz = node.z+dz[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&nz>=0&&nz<h){
                if(arr[nx][ny][nz]==0){
                    arr[nx][ny][nz]=1;
                    q.push({nx,ny,nz,node.day+1});
                    zeroCnt--;
                }
            }
        }
    }

    // 아직 안익은 토마토 남아있으면
    if(zeroCnt>0){
        cout<<-1<<"\n";
    }else{
        cout<<answer<<"\n";
    }

}