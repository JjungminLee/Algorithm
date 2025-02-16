#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
bool solved = false;

void printData()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

void backTracking(int idx)
{
    if (idx == 81)
    {
        printData();
        solved = true;
        return;
    }
    int x = idx / 9;
    int y = idx % 9;
    if (arr[x][y] != 0)
    {
        backTracking(idx + 1);
        return;
    }

    for (int num = 1; num <= 9; num++)
    {
        bool isValid = true;
        // 행 탐색
        for (int i = 0; i < 9; i++)
        {
            if (arr[x][i] == num || arr[i][y] == num)
            {
                isValid = false;
                break;
            }
        }
        if (!isValid)
        {
            continue;
        }
        int nx = (x / 3) * 3;
        int ny = (y / 3) * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[nx + i][ny + j] == num)
                {
                    isValid = false;
                    break;
                }
            }
        }
        if (!isValid)
        {
            continue;
        }
        else
        {
            arr[x][y] = num;
            backTracking(idx + 1);
            if (solved)
            {
                return;
            }
            arr[x][y] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }

    backTracking(0);
    return 0;
}
