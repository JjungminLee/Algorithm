#include<bits/stdc++.h>

using namespace std;
int n;
int sortArr[405];
vector<int>arr[405];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int sizeN;
int maps[25][25];
int ans;

void inputs(){
    cin>>n;
    sizeN = n*n;
    for(int i=0;i<sizeN;i++){
        int num;
        cin>>num;
        sortArr[i]=num;
        for(int j=0;j<4;j++){
            int tnum;
            cin>>tnum;
            arr[num].push_back(tnum);
        }
    }
}

int nearLikes(int x,int y,vector<int>likes){
    int cnt = 0;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        for(int l:likes){
            if(maps[nx][ny]==l){
                cnt++;
            }
        }
    }
    return cnt;
}

void nearVacant(int num,vector<int> likes){
    int maxCnt=0;
    int maxR=0;
    int maxC=0;
    int maxLike = -1;
    //3번 조건
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(maps[i][j] != 0) continue;
            //2번 조건
            int cnt = 0;
            for(int k=0;k<4;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(maps[nx][ny]==0){
                    cnt++;
                }
            }
            int like = nearLikes(i,j,likes);
            if(like>maxLike){
                maxLike = like;
                maxCnt = cnt;
                maxR = i;
                maxC= j;
            }else if(like==maxLike){
                if(cnt>maxCnt){
                    maxLike = like;
                    maxCnt = cnt;
                    maxR = i;
                    maxC= j;
                }
            }

        }
    }
    maps[maxR][maxC] = num;
}

void countSatisfaction(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num = maps[i][j];
            vector<int> likes = arr[num];
            int cnt = 0;
            for(int k=0;k<4;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(find(likes.begin(),likes.end(),maps[nx][ny])!=likes.end()){
                    cnt++;
                }
            }
            if(cnt==1){
                ans+=1;
            }else if(cnt==2){
                ans+=10;
            }else if(cnt==3){
                ans+=100;
            }else if(cnt==4){
                ans+=1000;
            }
        }
    }
}

void simualte(){
    for(int i=0;i<sizeN;i++){
        int curNum = sortArr[i];
        vector<int> likes;
        for(int j=0;j<4;j++){
            likes.push_back(arr[curNum][j]);
        }
        nearVacant(curNum,likes);
    }
}


int main(){
    inputs();
    simualte();
    countSatisfaction();
    cout<<ans<<"\n";
}