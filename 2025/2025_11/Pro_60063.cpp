#include <bits/stdc++.h>

using namespace std;
// 좌 우 상 하
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int sr = 0;
int sc = 0;
int N;

// 어떤 방향으로 방문했는지도(회전한 상태) visited에 기록해야 -> 보통 상하좌우에 회전까지 들어가면 회전상태를
// 인덱스로 같이 관리해야
// 최소 비용 구하기 위해서 visitied배열에 저장
int visited[101][101][2];

struct Node
{
    int r;
    int c;
    int dir; // 가로, 세로만 (어차피 앞뒤 구분 없다고 했으니)
    int cnt; // r,c,dir 로 오기까지 총합 시간 구하기
};

bool isInRange(int r, int c)
{
    if (r >= 0 && r < N && c >= 0 && c < N)
    {
        return true;
    }
    return false;
}

// BFS 문제중에 회전을 하면 이것도 visited배열에 회전 상태를 저장해야함
int solution(vector<vector<int>> board)
{
    int answer = 0;
    queue<Node> q;
    N = board.size();

    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                visited[i][j][k] = INT_MAX;
            }
        }
    }

    // 처음에  (1, 1) 위치에서 가로방향으로 놓여있는 상태로 시작
    visited[0][0][0] = 0;
    q.push({0, 0, 0, 0});

    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
        // 현재 2*1 로봇의 위치 (r1,c1) (r2,c2)
        int r1 = node.r;
        int c1 = node.c;
        int dir = node.dir;
        int cnt = node.cnt;

        if (cnt > visited[r1][c1][dir])
            continue;
        int r2 = 0;
        int c2 = 0;
        if (dir == 0)
        {
            // 가로
            r2 = r1;
            c2 = c1 + 1;
        }
        else if (dir == 1)
        {
            // 세로
            r2 = r1 + 1;
            c2 = c1;
        }

        if ((r1 == N - 1 && c1 == N - 1) || (r2 == N - 1 && c2 == N - 1))
        {
            return cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr1 = r1 + dr[i];
            int nc1 = c1 + dc[i];

            int nr2 = r2 + dr[i];
            int nc2 = c2 + dc[i];

            if (isInRange(nr1, nc1) && isInRange(nr2, nc2))
            {
                if (board[nr1][nc1] == 0 && board[nr2][nc2] == 0)
                {
                    if (visited[nr1][nc1][dir] > cnt + 1)
                    {
                        visited[nr1][nc1][dir] = cnt + 1;
                        q.push({nr1, nc1, dir, cnt + 1});
                    }
                }
            }
        }

        // 회전하기

        int ncnt = cnt + 1;

        if (dir == 0)
        {
            // 가로->세로로 회전

            // 아래로 회전
            // (r1+1,c1) 과 (r1+1,c1+1)은 비어있어야 한다
            if (isInRange(r1 + 1, c1) && isInRange(r1 + 1, c1 + 1) && board[r1 + 1][c1] == 0 && board[r1 + 1][c1 + 1] == 0)
            {
                // 어떤 지점에서 회전할 것인가
                //  r1,c1기준으로 회전
                if (visited[r1][c1][1] > ncnt)
                {
                    visited[r1][c1][1] = ncnt;
                    q.push({r1, c1, 1, ncnt});
                }

                if (visited[r1][c1 + 1][1] > ncnt)
                {
                    visited[r1][c1 + 1][1] = ncnt;
                    q.push({r1, c1 + 1, 1, ncnt});
                }
            }

            // 위로 회전
            if (isInRange(r1 - 1, c1 + 1) && isInRange(r1 - 1, c1) && board[r1 - 1][c1 + 1] == 0 && board[r1 - 1][c1] == 0)
            {
                if (visited[r1 - 1][c1][1] > ncnt)
                {
                    visited[r1 - 1][c1][1] = ncnt;
                    q.push({r1 - 1, c1, 1, ncnt});
                }

                if (visited[r1 - 1][c1 + 1][1] > ncnt)
                {
                    visited[r1 - 1][c1 + 1][1] = ncnt;
                    q.push({r1 - 1, c1 + 1, 1, ncnt});
                }
            }
        }
        else if (dir == 1)
        {
            // 세로->가로로 회전

            // 오른쪽방향으로 회전

            if (isInRange(r1, c1 + 1) && isInRange(r1 + 1, c1 + 1) && board[r1][c1 + 1] == 0 && board[r1 + 1][c1 + 1] == 0)
            {
                if (visited[r1][c1][0] > ncnt)
                {
                    visited[r1][c1][0] = ncnt;
                    q.push({r1, c1, 0, ncnt});
                }

                if (visited[r1 + 1][c1][0] > ncnt)
                {
                    visited[r1 + 1][c1][0] = ncnt;
                    q.push({r1 + 1, c1, 0, ncnt});
                }
            }

            // 왼쪽 방향으로 회전
            if (isInRange(r1, c1 - 1) && isInRange(r1 + 1, c1 - 1) && board[r1][c1 - 1] == 0 && board[r1 + 1][c1 - 1] == 0)
            {

                if (visited[r1][c1 - 1][0] > ncnt)
                {
                    visited[r1][c1 - 1][0] = ncnt;
                    q.push({r1, c1 - 1, 0, ncnt});
                }

                if (visited[r1 + 1][c1 - 1][0] > ncnt)
                {
                    visited[r1 + 1][c1 - 1][0] = ncnt;
                    q.push({r1 + 1, c1 - 1, 0, ncnt});
                }
            }
        }
    }

    return min(visited[N - 1][N - 1][0], visited[N - 1][N - 1][1]);
}