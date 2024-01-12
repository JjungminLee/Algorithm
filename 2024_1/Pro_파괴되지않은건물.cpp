

#include <bits/stdc++.h>
using namespace std;

// 누적합 아이디어를 가지고 고쳐보기!

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int boardRow = board.size();
    int boardCol = board[0].size();
    int skillRow = skill.size();
    int skillCol = skill[0].size();
    int dp[boardRow+1][boardCol+1];
    for(int i=0;i<boardRow+1;i++){
        for(int j=0;j<boardCol+1;j++){
            dp[i][j]=0;
        }
    }

 
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

        dp[startX][startY]+=degree;
        dp[startX][endY+1]+=degree*-1;
        dp[endX+1][startY]+=degree*-1;
        dp[endX+1][endY+1]+=degree;
   

    }
    // 세로로 누적합

    for(int i=0;i<boardCol;i++){
        for(int j=1;j<boardRow+1;j++){
            dp[j][i]+=dp[j-1][i];
    
        }
    }

    // 가로로 누적합

      for(int i=0;i<boardRow;i++){
        for(int j=1;j<boardCol+1;j++){
            dp[i][j]+=dp[i][j-1];
    
        }
    }



    for(int i=0;i<boardRow;i++){
        for(int j=0;j<boardCol;j++){
           
            
            board[i][j]+=dp[i][j];
      
            if(board[i][j]>=1){
                answer++;
            }
        }
   
    }
    
    return answer;
}



// int main(){


//     vector<vector<int>> board =   {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};
//     vector<vector<int>> skill ={{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
//     cout<<solution(board, skill)<<endl;
//     return 0;
// }

