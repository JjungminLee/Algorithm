#include <bits/stdc++.h>
using namespace std;
int m;
int n;
int arr[500][500];
int dx[4] = {
    -1,
    1,
    0,
    0};
int dy[4] = {0, 0, -1, 1};
int ans;
int dp[500][500];

int dfs(int x, int y)
{
    if (x == m - 1 && y == n - 1)
    {
        return 1;
    }
    // 이미 방문한거
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n)
        {

            if (arr[nx][ny] < arr[x][y])
            {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }
    return dp[x][y];
}
int main()
{
    cin >> m;
    cin >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0) << endl;
}