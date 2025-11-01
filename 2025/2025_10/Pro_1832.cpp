#include <bits/stdc++.h>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map)
{
    int answer = 0;
    vector<vector<int>> dp_right(m, vector<int>(n));
    vector<vector<int>> dp_down(m, vector<int>(n));
    dp_right[0][0] = 1;
    dp_down[0][0] = 1;
    // 첫 행 초기화
    for (int i = 1; i < n; i++)
    {
        // 이전 상태를 기준으로 생각해줌
        // 왼쪽에서 오른쪽으로 올수 있을까?
        if (city_map[0][i - 1] == 1)
        {
            dp_right[0][i] = 0;
        }
        else
        {
            dp_right[0][i] = dp_right[0][i - 1];
        }
        // 첫 행은 아래에서 내려올게 없다
        dp_down[0][i] = 0;
    }
    // 열 초기화
    for (int i = 1; i < m; i++)
    {
        if (city_map[i - 1][0] == 1)
        {
            dp_down[i][0] = 0;
        }
        else
        {
            dp_down[i][0] = dp_down[i - 1][0];
        }
        // 첫 열은 왼쪽에서 올게 없다
        dp_right[i][0] = 0;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // 위에서 아래로 올때
            if (city_map[i - 1][j] == 2)
            {
                dp_down[i][j] = dp_down[i - 1][j];
            }
            else if (city_map[i - 1][j] == 0)
            {
                dp_down[i][j] = (dp_down[i - 1][j] + dp_right[i - 1][j]) % MOD;
            }
            // 왼쪽에서 오른쪽으로 올때
            if (city_map[i][j - 1] == 2)
            {
                dp_right[i][j] = dp_right[i][j - 1];
            }
            else if (city_map[i][j - 1] == 0)
            {
                dp_right[i][j] = (dp_down[i][j - 1] + dp_right[i][j - 1]) % MOD;
            }
            if (city_map[i][j] == 1)
            {
                dp_down[i][j] = 0;
                dp_right[i][j] = 0;
            }
        }
    }
    return (dp_down[m - 1][n - 1] + dp_right[m - 1][n - 1]) % MOD;
}