#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[51][51];
bool visits[51][51];
int minAns = INT_MAX;
vector<pair<int,int>> chickenHouse;
vector<pair<int,int>> house;

void dfs(int idx,int depth){
    if(depth==M){

        // 집 입장에서 치킨집들의 벡터 중 자기랑 가장 작은 치킨거리 갖고 있는데 애 더해서 마지막에 min계산
        vector<pair<int,int>> chicken ;
        int cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(visits[i][j]){
                    chicken.push_back({i,j});
                }
            }
        }

        for(int i=0;i<house.size();i++){
            int x = house[i].first;
            int y = house[i].second;
            int chickenDistance=INT_MAX;
            for(int k=0;k<chicken.size();k++){
                    int temp;
                    int cx = chicken[k].first;
                    int cy = chicken[k].second;
                       
                    temp=abs(cx-x)+abs(cy-y);
                     
                    chickenDistance=min(chickenDistance,temp);
            }
                   
            cnt+=chickenDistance;
        }
       
        minAns=min(minAns,cnt);

        

    }
    for(int i=idx;i<chickenHouse.size();i++){
        int x = chickenHouse[i].first;
        int y = chickenHouse[i].second;
        if(arr[x][y]==2&&!visits[x][y]){
                visits[x][y]=true;
                dfs(i+1,depth+1);
                visits[x][y]=false;
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                chickenHouse.push_back({i,j});

            }
            if(arr[i][j]==1){
                house.push_back({i,j});
            }
        }
    }
    dfs(0,0);
    cout<<minAns<<endl;

}