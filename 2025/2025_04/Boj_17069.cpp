#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[3][32][32];
long long arr[32][32];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    // 끝점일때 마킹한다!
    dp[0][0][1] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[0][i][j] > 0)
            {
                if (j + 1 < n && arr[i][j + 1] == 0)
                {
                    dp[0][i][j + 1] += dp[0][i][j];
                }
                if (j + 1 < n && i + 1 < n && arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0)
                {
                    dp[2][i + 1][j + 1] += dp[0][i][j];
                }
            }
            if (dp[1][i][j] > 0)
            {
                if (i + 1 < n && arr[i + 1][j] == 0)
                {
                    dp[1][i + 1][j] += dp[1][i][j];
                }
                if (j + 1 < n && i + 1 < n && arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0)
                {
                    dp[2][i + 1][j + 1] += dp[1][i][j];
                }
            }
            if (dp[2][i][j] > 0)
            {
                if (j + 1 < n && arr[i][j + 1] == 0)
                {
                    dp[0][i][j + 1] += dp[2][i][j];
                }
                if (i + 1 < n && arr[i + 1][j] == 0)
                {
                    dp[1][i + 1][j] += dp[2][i][j];
                }
                if (j + 1 < n && i + 1 < n && arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0)
                {
                    dp[2][i + 1][j + 1] += dp[2][i][j];
                }
            }
        }
    }

    cout << dp[0][n - 1][n - 1] + dp[1][n - 1][n - 1] + dp[2][n - 1][n - 1] << endl;
}