#include<bits/stdc++.h>

using namespace std;

int N;
int M;
int H;
bool ladder[40][40];
int ans = 4;

bool check(){
    for(int start=1;start<=N;start++){
        int pos = start;
        for(int r=1;r<=H;r++){
            if(ladder[r][pos]){
                pos++;
            }else if(ladder[r][pos-1]){
                pos--;
            }
        }
        if(pos!=start){
            return false;
        }
    }

    return true;

}

void backtracking(int idx,int cnt){
    if(cnt>=ans){
        return;
    }
    if(check()){
        ans=cnt;
        return;
    }

    for(int r=idx;r<=H;r++){
        for(int c=1;c<N;c++){
            if(ladder[r][c]) continue;
            if(ladder[r][c-1]||ladder[r][c+1]) continue;
            ladder[r][c]=true;
            backtracking(r,cnt+1);
            ladder[r][c]=false;
        }
    }

}

int main(){
    cin>>N>>M>>H;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        ladder[a][b]=true;
    }

    backtracking(1,0);
    if(ans>3){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
    }

    return 0;

}