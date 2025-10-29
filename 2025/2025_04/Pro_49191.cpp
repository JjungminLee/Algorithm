#include <bits/stdc++.h>
int arr[101][101];

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    for (int i = 0; i < results.size(); i++)
    {
        int a = results[i][0];
        int b = results[i][1];
        arr[a][b] = 1;
        arr[b][a] = -1;
    }
    // 경유지 출발지 도착지
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][k] == -1 && arr[j][k] == 1)
                {
                    arr[i][j] = -1;
                    arr[j][i] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] != 0)
            {
                cnt++;
            }
        }
        if (cnt == n - 1)
        {
            answer++;
        }
    }
    return answer;
}