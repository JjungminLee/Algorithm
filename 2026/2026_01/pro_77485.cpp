#include <bits/stdc++.h>
using namespace std;

int arr[105][105];
vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    int num = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            arr[i][j] = num;
            num++;
        }
    }

    vector<int> answer;
    for (int i = 0; i < queries.size(); i++)
    {
        int x1 = queries[i][0] - 1;
        int y1 = queries[i][1] - 1;
        int x2 = queries[i][2] - 1;
        int y2 = queries[i][3] - 1;

        int rotateArr[105][105] = {-1};

        for (int i = 0; i < 105; i++)
        {
            for (int j = 0; j < 105; j++)
            {
                rotateArr[i][j] = arr[i][j];
            }
        }

        // 맨위 오른쪽으로
        for (int c = y1; c <= y2 - 1; c++)
        {
            int prev = arr[x1][c];
            rotateArr[x1][c + 1] = prev;
        }

        // 왼쪽 세로줄 위로
        for (int r = x2; r >= x1 + 1; r--)
        {
            int prev = arr[r][y1];
            rotateArr[r - 1][y1] = prev;
        }

        // 오른쪽 세로줄 밑으로
        for (int r = x1; r <= x2 - 1; r++)
        {
            int prev = arr[r][y2];
            rotateArr[r + 1][y2] = prev;
        }

        // 맨 아래 왼쪽으로
        for (int c = y2; c >= y1 + 1; c--)
        {
            int prev = arr[x2][c];
            rotateArr[x2][c - 1] = prev;
        }

        vector<int> tmp;

        for (int r = x1; r <= x2; r++)
        {
            if (rotateArr[r][y1] != arr[r][y1])
            {
                tmp.push_back(rotateArr[r][y1]);
            }

            if (rotateArr[r][y2] != arr[r][y2])
            {
                tmp.push_back(rotateArr[r][y2]);
            }
        }

        for (int c = y1; c <= y2; c++)
        {
            if (rotateArr[x1][c] != arr[x1][c])
            {
                tmp.push_back(rotateArr[x1][c]);
            }

            if (rotateArr[x2][c] != arr[x2][c])
            {
                tmp.push_back(rotateArr[x2][c]);
            }
        }

        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[0]);

        for (int i = 0; i < 105; i++)
        {
            for (int j = 0; j < 105; j++)
            {
                arr[i][j] = rotateArr[i][j];
            }
        }
    }
    return answer;
}