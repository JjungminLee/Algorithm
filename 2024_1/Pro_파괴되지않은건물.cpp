
#include <bits/stdc++.h>
using namespace std;


int solution(vector<vector<int>>& board, vector<vector<int>>& skill) {
    int answer = 0;
    int boardRow = board.size();
    int boardCol = board[0].size();
    int skillRow = skill.size();
    int skillCol = skill[0].size();

 
    for(int i=0;i<skillRow;i++){
        int type = skill[i][0];
        int startX = skill[i][1];
        int startY= skill[i][2];
        int endX = skill[i][3];
        int endY = skill[i][4];
        int degree=0;
        if(type==1){
            degree=-1*skill[i][5];
        }else{
            degree=skill[i][5];
        }
        for(int j=startX;j<=endX;j++){
            for(int k=startY;k<=endY;k++){
               
                board[j][k]+=degree;
                //cout<<board[j][k]<<" ";
            }
            //cout<<endl;

        }
       //cout<<"---------"<<endl;

    }
    for(int i=0;i<boardRow;i++){
        for(int j=0;j<boardCol;j++){
            //cout<<board[i][j]<<" ";
            if(board[i][j]>0){
                
                answer+=1;

            }
        }
        //cout<<endl;
    }
    
    return answer;
}
int main(){


    vector<vector<int>> board =   {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> skill = {{1,1,1,2,2,4},{1,0,0,1,1,2},{2,2,0,2,0,100}};
    cout<<solution(board, skill)<<endl;
    return 0;
}

