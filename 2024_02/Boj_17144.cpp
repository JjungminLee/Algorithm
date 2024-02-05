#include <bits/stdc++.h>

using namespace std;
int R,C,T;
int arr[51][51];
int add[51][51];
int ans;
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
vector<pair<int,int>> purify;
int px1,py1,px2,py2;



void diffusion(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(arr[i][j]>0){
                int rate = arr[i][j]/5; 
                int cnt = 0;              
                for(int k=0;k<4;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx>=0&&nx<R&&ny>=0&&ny<C){
                        if(arr[nx][ny]!=-1){
                            add[nx][ny]+= rate;
                            cnt++;
                        }
                    }
                }
                add[i][j]-=(cnt*rate);
            }

        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            arr[i][j]+=add[i][j];
            add[i][j]=0;
        }
    }
    

}
void purifyTop(){
    int backup[51][51];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            backup[i][j]=arr[i][j];
        }
    }
    // 우
    arr[px1][1]=0;
    for(int i=2;i<C;i++){
        arr[px1][i]=backup[px1][i-1];
    }

    // 상
    for(int i=px1-1;i>=0;i--){
        arr[i][C-1]=backup[i+1][C-1];
    }
    // 좌
    for(int i=C-2;i>=0;i--){
        arr[0][i]=backup[0][i+1];
    }

    //하
    for(int i=1;i<px1;i++){
        arr[i][0]=backup[i-1][0];
    }


}
void purifyBelow(){
    int backup[51][51];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            backup[i][j]=arr[i][j];
        }
    }
    // 우
    arr[px2][1]=0;
    for(int i=2;i<C;i++){
        arr[px2][i]=backup[px2][i-1];
    }
    // 하
    for(int i=px2+1;i<R;i++){
        arr[i][C-1]=backup[i-1][C-1];
    }
    // 좌
    for(int i=C-2;i>=0;i--){
        arr[R-1][i]=backup[R-1][i+1];
    }
    //상
    for(int i=R-2;i>px2;i--){
        arr[i][0]=backup[i+1][0];
    }

   

}
void simulation(int time){
    if(time==T){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(arr[i][j]>0){
                    ans+=arr[i][j];
                }
            }
        }
        return;
    }
    diffusion();

    purifyTop();
    purifyBelow();

    simulation(time+1);

}
int main(){
    ios::sync_with_stdio(0);
    cin>>R>>C>>T;
    ans = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>arr[i][j];
            if(arr[i][j]==-1){
                purify.push_back({i,j});
            }
        }
    }
    px1=purify[0].first;
    py1=purify[0].second;
    px2=purify[1].first;
    py2=purify[1].second;
    simulation(0);
    cout<<ans<<endl;
    
}