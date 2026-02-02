#include <bits/stdc++.h>

using namespace std;

int arr[105][105];
int dx[8] = {0, 0, -1, 1, -1, 1, 1, -1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                arr[i][j] = 1;
                for (int k = 0; k < 8; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        arr[nx][ny] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                answer++;
            }
        }
    }
    return answer;
}