#include <bits/stdc++.h>

using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int n = triangle.size();
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        int len = triangle[i].size();
        for (int j = 0; j < len; j++)
        {
            if (j == 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
            }
            else if (j == len - 1)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
            }
        }
    }

    for (int i = 0; i < triangle[n - 1].size(); i++)
    {
        answer = max(answer, dp[n - 1][i]);
    }
    return answer;
}