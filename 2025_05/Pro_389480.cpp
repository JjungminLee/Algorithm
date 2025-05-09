#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    int dp[41][121];
    int answer = 2e9;
    for (int i = 0; i < 41; i++)
    {
        for (int j = 0; j < 121; j++)
        {
            dp[i][j] = 2e9;
        }
    }
    // dp[i][j] => i번째까지 훔쳤고 b를 j만큼 훔쳤을때 a가 훔친 누적 최소 합
    // 처음에도 훔칠수 있는지 판단하는게 중요함
    if (info[0][1] < m)
    {
        dp[0][info[0][1]] = 0;
    }
    if (info[0][0] < n)
    {
        dp[0][0] = info[0][0];
    }

    for (int i = 1; i < info.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {

            // a가 훔치는 경우
            int stealA = dp[i - 1][j] + info[i][0];
            if (stealA < n)
            {
                dp[i][j] = min(dp[i][j], stealA);
            }
            // b가 훔치는 경우
            int stealB = j + info[i][1];
            if (stealB < m)
            {
                dp[i][stealB] = min(dp[i - 1][j], dp[i][stealB]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        answer = min(dp[info.size() - 1][i], answer);
    }
    if (answer == 2e9)
    {
        return -1;
    }

    return answer;
}