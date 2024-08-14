#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];
int N, M;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Ball
{
    int rx, ry, bx, by, depth;
};

bool isInside(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs(Ball start)
{
    queue<Ball> q;
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = true;

    while (!q.empty())
    {
        Ball cur = q.front();
        q.pop();

        if (cur.depth > 10)
            return -1;
        if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O')
            return cur.depth;

        for (int dir = 0; dir < 4; ++dir)
        {
            int next_rx = cur.rx;
            int next_ry = cur.ry;
            int next_bx = cur.bx;
            int next_by = cur.by;

            while (isInside(next_rx + dx[dir], next_ry + dy[dir]) && board[next_rx + dx[dir]][next_ry + dy[dir]] != '#' && board[next_rx][next_ry] != 'O')
            {
                next_rx += dx[dir];
                next_ry += dy[dir];
            }

            while (isInside(next_bx + dx[dir], next_by + dy[dir]) && board[next_bx + dx[dir]][next_by + dy[dir]] != '#' && board[next_bx][next_by] != 'O')
            {
                next_bx += dx[dir];
                next_by += dy[dir];
            }
            // 둘이 겹쳐지는데 red가 홀에 가진 않았을때
            //  더 먼저 그 위치에 도착한 구슬을 유지하고 나중에 도착한 구슬을 한 칸 뒤로 보내는 로직

            if (next_rx == next_bx && next_ry == next_by && board[next_rx][next_ry] != 'O')
            {
                // 빨간 구슬이 더 많이 이동한 경우
                if (abs(next_rx - cur.rx) + abs(next_ry - cur.ry) > abs(next_bx - cur.bx) + abs(next_by - cur.by))
                {
                    next_rx -= dx[dir];
                    next_ry -= dy[dir];
                }
                else
                {
                    next_bx -= dx[dir];
                    next_by -= dy[dir];
                }
            }

            if (!visited[next_rx][next_ry][next_bx][next_by])
            {
                visited[next_rx][next_ry][next_bx][next_by] = true;
                q.push({next_rx, next_ry, next_bx, next_by, cur.depth + 1});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    Ball start;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                start.rx = i;
                start.ry = j;
            }
            if (board[i][j] == 'B')
            {
                start.bx = i;
                start.by = j;
            }
        }
    }
    start.depth = 0;
    cout << bfs(start) << endl;
    return 0;
}
