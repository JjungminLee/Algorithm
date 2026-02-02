#include <bits/stdc++.h>

using namespace std;
int dp[105][105];
bool block[105][105];
int mod = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    for (int i = 0; i < puddles.size(); i++)
    {
        int a = puddles[i][0];
        int b = puddles[i][1];
        block[b][a] = true;
    }

    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (block[i][j])
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 1 && j == 1)
            {
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    answer = dp[n][m] % mod;
    return answer;
}