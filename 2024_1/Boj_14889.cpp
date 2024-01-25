#include <bits/stdc++.h>
using namespace std;
int N;
int arr[21][21];
int minAns = INT_MAX;
bool visits[21];

void dfs(int idx,int depth){
    vector<int>start={};
    vector<int>link={};
    int startCnt=0;
    int linkCnt=0;
    if(depth==N/2){
        for(int i=0;i<N;i++){
            if(visits[i]){
                start.push_back(i);
            }else{
                link.push_back(i);
            }
        }
      
        for(int i=0;i<start.size();i++){
          for(int j=0;j<start.size();j++){
            startCnt+=arr[start[i]][start[j]];
          }
        }
         for(int i=0;i<link.size();i++){
          for(int j=0;j<link.size();j++){
            linkCnt+=arr[link[i]][link[j]];
          }
        }

        minAns=min(minAns,abs(startCnt-linkCnt));
      
        return;
    }else{
        for(int i=idx;i<N;i++){
            if(!visits[i]){
                visits[i]=true;
                dfs(i,depth+1);
                visits[i]=false;
            }
        }
    }
}
int main(){
    cin>>N;
    vector<int> start;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    dfs(0,0);

    cout<<minAns<<endl;

}