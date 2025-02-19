#include <bits/stdc++.h>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map)
{
    vector<vector<int>> dp_right(m, vector<int>(n, 0));
    vector<vector<int>> dp_down(m, vector<int>(n, 0));

    dp_right[0][0] = dp_down[0][0] = 1;

    // 첫 행 초기화 (dp에서 처음에 초기화 하는 작업)
    for (int j = 1; j < n; j++)
    {
        if (city_map[0][j - 1] == 1)
        {
            dp_right[0][j] = 0;
        }
        else if (city_map[0][j - 1] == 2)
        {
            dp_right[0][j] = dp_right[0][j - 1];
        }
        else
        {
            dp_right[0][j] = dp_right[0][j - 1];
        }
        dp_down[0][j] = 0; // 첫 행은 위쪽에서 내려올 수 없음
    }

    // 첫 열 초기화
    for (int i = 1; i < m; i++)
    {
        if (city_map[i - 1][0] == 1)
        {
            dp_down[i][0] = 0;
        }
        else if (city_map[i - 1][0] == 2)
        {
            dp_down[i][0] = dp_down[i - 1][0];
        }
        else
        {
            dp_down[i][0] = dp_down[i - 1][0];
        }
        dp_right[i][0] = 0; // 첫 열은 왼쪽에서 올 수 없음
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (city_map[i - 1][j] == 2)
            {

                dp_down[i][j] = dp_down[i - 1][j];
            }
            else if (city_map[i - 1][j] == 0)
            {

                dp_down[i][j] = (dp_down[i - 1][j] + dp_right[i - 1][j]) % MOD;
            }

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