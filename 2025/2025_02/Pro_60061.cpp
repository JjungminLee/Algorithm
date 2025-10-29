#include <bits/stdc++.h>

using namespace std;
int arr[1002][1002][2];
bool canInstallGidoong(int x, int y, int n)
{
    if (y == 0)
    {
        return true;
    }
    if (arr[x][y][1] == 1)
    {
        // 오른쪽 끝에 보가 있는지?
        return true;
    }
    if (x - 1 >= 0 && arr[x - 1][y][1] == 1)
    {
        // 왼쪽 끝에 보가 있는지?
        return true;
    }
    if (y - 1 >= 0 && arr[x][y - 1][0] == 1)
    {
        // 아래가 기둥인지
        return true;
    }
    return false;
}

bool canInstallBo(int x, int y, int n)
{
    // 양쪽이 보로 이루어져있는지
    if (x - 1 >= 0 && x + 1 <= n && arr[x - 1][y][1] == 1 && arr[x + 1][y][1] == 1)
    {
        return true;
    }
    // 보의 왼쪽 끝 아래에 기둥이 있는지
    if (y - 1 >= 0 && arr[x][y - 1][0] == 1)
    {
        return true;
    }
    // 보의 오른쪽 끝 아래에 기둥이 있는지
    if (y - 1 >= 0 && x + 1 <= n && arr[x + 1][y - 1][0] == 1)
    {
        return true;
    }
    return false;
}

bool isValid(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (arr[i][j][0] == 1 && !canInstallGidoong(i, j, n))
            {
                return false;
            }
            if (arr[i][j][1] == 1 && !canInstallBo(i, j, n))
            {
                return false;
            }
        }
    }

    return true;
}

void removeGidoong(int x, int y, int n)
{
    arr[x][y][0] = 0;
    if (!isValid(n))
    {
        arr[x][y][0] = 1;
    }
}

void removeBo(int x, int y, int n)
{
    arr[x][y][1] = 0;
    if (!isValid(n))
    {
        arr[x][y][1] = 1;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x, y, a, b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];
        // 기둥
        if (a == 0)
        {
            if (b == 0)
            {
                removeGidoong(x, y, n);
            }
            else
            {
                if (canInstallGidoong(x, y, n))
                {
                    arr[x][y][0] = 1;
                }
            }
        }
        else if (a == 1)
        {
            if (b == 0)
            {
                removeBo(x, y, n);
            }
            else
            {
                if (canInstallBo(x, y, n))
                {
                    arr[x][y][1] = 1;
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (arr[i][j][0] == 1)
            {
                answer.push_back({i, j, 0});
            }
            if (arr[i][j][1] == 1)
            {
                answer.push_back({i, j, 1});
            }
        }
    }

    return answer;
}