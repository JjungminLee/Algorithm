#include <bits/stdc++.h>
using namespace std;
int N,L,R;
int arr[51][51];
int ans;
int visits[51][51];
int dirX[4]={-1,1,0,0};
int dirY[4]={0,0,-1,1};
bool flag;



void bfs(int x,int y){


    queue<pair<int,int>> q;
    vector<pair<int,int>> v;
    int unionCnt=1;
    int cnt = arr[x][y];
    if(visits[x][y]){
        return;
    }
    
    q.push({x,y});
    v.push_back({x,y});
    visits[x][y]=true;
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
  
        q.pop();
        visits[x][y]=true;
        for(int i=0;i<4;i++){
            int nx = x+dirX[i];
            int ny = y+dirY[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N){
                if(abs(arr[x][y]-arr[nx][ny])>=L &&abs(arr[x][y]-arr[nx][ny])<=R){
                    if(!visits[nx][ny]){
                        q.push({nx,ny});
                        cnt+=arr[nx][ny];
                        unionCnt++;
                        flag=true;
                        v.push_back({nx,ny});
                        visits[nx][ny]=true;
                    

                    }
                }
            }

        }
    
    }
   

    for(int i=0;i<v.size();i++){
            int x = v[i].first;
            int y = v[i].second;
            arr[x][y]=cnt/unionCnt;
    }
    


}

int main(){
    cin>>N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
   
    

    while(true){

        // 국경 열렸는지 판단
        flag = false;
  
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                bfs(i,j);
            }
         }
         if(flag==false){
            break;
         }else{
            ans++;
         }
          for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                visits[i][j]=false;
            }
         }
        
        
      
    } 
   

    cout<<ans<<endl;
    

  


}