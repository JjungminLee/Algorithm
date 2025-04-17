#include <bits/stdc++.h>
using namespace std;
int t, m, n, k;
int arr[51][51];
bool visited[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans;
void clears()
{
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            arr[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});

    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && arr[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;

    for (int l = 0; l < t; l++)
    {
        cin >> n >> m >> k;
        clears();
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            arr[a][b] = 1;
        }
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1 && !visited[i][j])
                {
                    bfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}