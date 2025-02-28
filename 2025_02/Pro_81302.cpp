#include <bits/stdc++.h>
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dgX[4] = {-1, 1, 1, -1};
int dgY[4] = {-1, 1, -1, 1};

using namespace std;

bool checking(vector<string> v, int x, int y)
{
    // 상하좌우 (1칸) 바로 양 옆 위아래에 사람이 있다면 안됨!
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && v[nx][ny] == 'P')
        {
            return false;
        }
    }

    // 상하좌우 (2칸)
    for (int i = 0; i < 4; i++)
    {
        int nx = x + 2 * dx[i];
        int ny = y + 2 * dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && v[nx][ny] == 'P')
        {
            // 중간에 파티션이 없다면
            if (v[x + dx[i]][y + dy[i]] != 'X')
            {
                return false;
            }
        }
    }

    // 대각선
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dgX[i];
        int ny = y + dgY[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && v[nx][ny] == 'P')
        {
            if (v[nx][y] != 'X' || v[x][ny] != 'X')
            {
                return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    for (int i = 0; i < 5; i++)
    {
        vector<string> v = places[i];
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (v[j][k] == 'P')
                {
                    if (!checking(v, j, k))
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    return answer;
}