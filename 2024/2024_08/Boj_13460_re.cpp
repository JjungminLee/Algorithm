#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[11][11];
bool visited[11][11][11][11];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
struct Ball
{
    int rx, ry, bx, by, depth;
};
bool inside(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}
int bfs(Ball ball)
{
    queue<Ball> q;
    q.push(ball);
    visited[ball.rx][ball.ry][ball.bx][ball.by] = true;
    while (!q.empty())
    {
        Ball cur = q.front();
        q.pop();
        if (cur.depth > 10)
        {
            return -1;
        }
        if (arr[cur.rx][cur.ry] == 'O' && arr[cur.bx][cur.by] != 'O')
        {
            return cur.depth;
        }
        for (int i = 0; i < 4; i++)
        {
            int rnx = cur.rx;
            int rny = cur.ry;
            int bnx = cur.bx;
            int bny = cur.by;
            // 벽은 다음을 대비해야하고, 구멍은 우선 들어가야하니까 다음을 고려할 필요 없다
            while (inside(rnx + dx[i], rny + dy[i]) && arr[rnx + dx[i]][rny + dy[i]] != '#' && arr[rnx][rny] != 'O')
            {
                rnx += dx[i];
                rny += dy[i];
            }
            while (inside(bnx + dx[i], bny + dy[i]) && arr[bnx + dx[i]][bny + dy[i]] != '#' && arr[bnx][bny] != 'O')
            {
                bnx += dx[i];
                bny += dy[i];
            }
            // 겹쳐질때, 더 많이 이동하는 애가 늦게 도착할거니까 걔를 한칸 뒤로 그리고 빨간공이 홀에 들어가지 않을때!
            if (rnx == bnx && rny == bny && arr[rnx][rny] != 'O')
            {
                if (abs(rnx - cur.rx) + abs(rny - cur.ry) > abs(bnx - cur.bx) + abs(bny - cur.by))
                {
                    rnx -= dx[i];
                    rny -= dy[i];
                }
                else
                {
                    bnx -= dx[i];
                    bny -= dy[i];
                }
            }
            if (!visited[rnx][rny][bnx][bny])
            {
                visited[rnx][rny][bnx][bny] = true;
                q.push({rnx, rny, bnx, bny, cur.depth + 1});
            }
        }
    }

    return -1;
}
int main()
{
    cin >> n >> m;
    Ball ball;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'R')
            {
                ball.rx = i;
                ball.ry = j;
            }
            else if (arr[i][j] == 'B')
            {
                ball.bx = i;
                ball.by = j;
            }
        }
    }
    ball.depth = 0;
    cout << bfs(ball) << endl;
}