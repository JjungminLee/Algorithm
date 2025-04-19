#include <bits/stdc++.h>

using namespace std;
int arr[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < skill.size(); i++)
    {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        if (type == 1)
        {
            degree = (-1) * degree;
        }
        // 얼마나 더하거나 뺄건지만 인덱스에 표시
        arr[r1][c1] += degree;
        arr[r1][c2 + 1] -= degree;
        arr[r2 + 1][c1] -= degree;
        arr[r2 + 1][c2 + 1] += degree;
    }
    // 좌우 누적합
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }
    // 상하 누적합
    for (int j = 0; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            arr[i][j] += arr[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (board[i][j] + arr[i][j] > 0)
            {
                answer++;
            }
        }
        cout << endl;
    }
    return answer;
}