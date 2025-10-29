#include <bits/stdc++.h>

using namespace std;

int k;
int x,y,d,g;
int arr[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
vector<int> v;
int cnt;
void makeCurve(){
    int size = v.size()-1;

    for(int i=size;i>=0;i--){
        int nd = (v[i]+1)%4;
        x+=dx[nd];
        y+=dy[nd];
        v.push_back(nd);
        arr[x][y]=1;
    }

  

}

void countSquare(){
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(i+1<=100&&j+1<=100){
                if(arr[i][j]==1&&arr[i+1][j]==1&&arr[i][j+1]==1&&arr[i+1][j+1]==1){
                    cnt++;
                }
            }
        }
    }

}

int main(){
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>x>>y>>d>>g;
        v.clear();
        arr[x][y]=1;
        v.push_back(d);
        //0세대
        x += dx[d];
        y += dy[d];
        arr[x][y]=1;
        for(int j=1;j<=g;j++){
            makeCurve();
        }
        
    }
    countSquare();
    cout<<cnt<<endl;

}