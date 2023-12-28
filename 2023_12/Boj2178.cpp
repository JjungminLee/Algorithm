#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N;
int M;
vector<vector<int>> v;
int cnt = 0;
int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, -1, 1};


int Bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
    
        
        for (int i = 0; i < 4; i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
         
            
            if (newX >= 0 && newX < N && newY >= 0 && newY < M ) {
                if(v[newX][newY] == 1){
                       v[newX][newY] = v[x][y] + 1;
                       q.push({newX,newY});
                }
            }
        }
    }
    return v[N-1][M-1];
}

int main() {
    cin >> N>>M;
    
    for (int i = 0; i < N; i++) {
        vector<int> row;
    
        
        for (int j = 0; j < M; j++) {
            char num;
            cin >> num;
            // 문자열 숫자로 변환
            row.push_back(num - '0');
    
        }
        
        v.push_back(row);

    }

    cout<< Bfs(0, 0)<<endl;
    return 0;
}
