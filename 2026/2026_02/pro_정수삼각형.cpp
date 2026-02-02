#include <bits/stdc++.h>

using namespace std;

int arr[505][505];
int dp[505][505];
int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int m = triangle.size() - 1;
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            arr[i][j] = triangle[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
            }
        }
    }
    for (int i = 0; i < triangle[m].size(); i++)
    {
        answer = max(dp[m][i], answer);
    }
    return answer;
}