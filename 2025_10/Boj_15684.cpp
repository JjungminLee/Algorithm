#include<bits/stdc++.h>

using namespace std;

int N;
int M;
int H;
bool ladder[40][40];
int answer=4;

bool check(){
    for(int start=1;start<=N;start++){
        int pos = start;
        for(int row=1;row<=H;row++){
            // 가로선이 있으면 옆에 열로 넘어감
            if(ladder[row][pos]){
                pos++;
            }else if(ladder[row][pos-1]){
                pos--;
            }
        }
        if(pos!=start){
            return false;
        }
    }
    return true;

}

// 백트래킹은 가로선 추가 가능한지 탐색
void backTracking(int idx,int cnt){
    // 가로선 추가 
    // 1. 두 가로선 연속 x
    // 2. 접하면 x
    if(cnt>=answer){
        return;
    }

    if(check()){
        // i번의 세로선 결과에 i가 나온 경우
        answer = cnt;
        return;
    }

    for(int r= idx;r<=H;r++){
        for(int c=1;c<N;c++){
            if(ladder[r][c]) continue;
            if(c<N-1&&(ladder[r][c-1]||ladder[r][c+1])) continue;
            ladder[r][c]=true;
            // r+1이 아닌 이유! -> 같은 행이여도 떨어지는 경우 발생하기 때문에 r을 넣어야!
            backTracking(r,cnt+1);
            ladder[r][c]=false;
        }
    }



}

int main(){
    cin>>N>>M>>H;
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        // a번 가로줄에서 b번 세로선과 b+1번 세로선을 연결
        ladder[a][b]=true;
    }

    backTracking(1,0);
    if(answer>3){
        cout<<-1<<"\n";
    }else{
        cout<<answer<<"\n";
    }

}