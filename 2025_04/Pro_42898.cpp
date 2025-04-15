#include <bits/stdc++.h>
long long dp[101][101];

using namespace std;
long long MAX = 1000000;
long long DIV = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;

    for (int i = 0; i < puddles.size(); i++)
    {
        int a = puddles[i][0];
        int b = puddles[i][1];
        dp[b - 1][a - 1] = -10;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (dp[i][j] == -10)
            {
                continue;
            }
            if (i >= 1 && dp[i - 1][j] != -10)
            {
                dp[i][j] += dp[i - 1][j] % DIV;
            }
            if (j >= 1 && dp[i][j - 1] != -10)
            {
                dp[i][j] += dp[i][j - 1] % DIV;
            }
        }
    }
    answer = dp[n - 1][m - 1] % DIV;
    return answer;
}