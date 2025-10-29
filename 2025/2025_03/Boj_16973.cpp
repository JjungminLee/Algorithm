#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1001][1001];
int sum[1001][1001];
bool visited[1001][1001];
int h, w;
int sx, sy;
int fx, fy;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool findRange(int x, int y)
{
    // 직사각형이 범위에 들어가는지 확인
    if (x >= 1 && y >= 1 && x + h - 1 <= n && y + w - 1 <= m)
    {
        return true;
    }
    return false;
}
int getSum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int bfs()
{
    queue<pair<int, pair<int, int>>> q;
    // 큐는 시작점만 넣기
    q.push({0, {sx, sy}});
    visited[sx][sy] = true;
    while (!q.empty())
    {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        if (x == fx && y == fy)
        {
            return cnt;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (visited[nx][ny])
            {
                continue;
            }
            if (findRange(nx, ny) && !visited[nx][ny])
            {
                // 벽이 아님
                if (getSum(nx, ny, nx + h - 1, ny + w - 1) == 0)
                {
                    visited[nx][ny] = true;
                    q.push({cnt + 1, {nx, ny}});
                }
            }
        }
    }
    return -1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    cin >> h >> w >> sx >> sy >> fx >> fy;

    int ans = bfs();
    cout << ans << endl;
}