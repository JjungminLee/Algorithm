#include <bits/stdc++.h>
using namespace std;

int N, M;
int r, c, d;
int arr[52][52];
//상 우 하 좌
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;

void dfs(int x, int y, int d) {
    if(arr[x][y]==0){
        arr[x][y]=2;
        cnt++;
    }

    for (int i = 0; i < 4; i++) {
        int nd = (d + 3-i) % 4; // 방향 설정 수정
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (arr[nx][ny] == 0) {
                dfs(nx, ny, nd);
            }
        }
    }
    int back = (d + 2) % 4;
    int bx = x + dx[back];
    int by = y + dy[back];
    if (bx >= 0 && bx < N && by >= 0 && by < M) {
        if (arr[bx][by] == 1) {
            cout<<cnt<<endl;
            exit(0);
            
        } 
    }
    dfs(bx, by, d);
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(r, c, d);


    return 0;
}
