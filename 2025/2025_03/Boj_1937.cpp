#include <bits/stdc++.h>
using namespace std;

int n;
int arr[501][501];
int dp[501][501];
int visited[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans;

int dfs(int x, int y)
{
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
        {
            if (arr[x][y] < arr[nx][ny])
            {
                dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
            }
        }
    }
    return dp[x][y];
}
int main()
{
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dfs(i, j);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << endl;
}