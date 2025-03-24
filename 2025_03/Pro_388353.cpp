#include <bits/stdc++.h>
using namespace std;
char arr[51][51];
int row, col;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<string> storage, vector<string> requests)
{
    row = storage.size();
    col = storage[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = storage[i][j];
        }
    }

    for (string req : requests)
    {
        if (req.size() == 1)
        {

            char target = req[0];
            bool visited[51][51] = {
                false,
            };
            bool accessible[51][51] = {
                false,
            };
            queue<pair<int, int>> q;
            // 빈칸들 먼저 연결하고, 접근 가능한지 판단
            for (int i = 0; i < col; i++)
            {
                if (!visited[0][i] && arr[0][i] == '\0')
                {
                    visited[0][i] = true;
                    q.push({0, i});
                }
                if (!visited[row - 1][i] && arr[row - 1][i] == '\0')
                {
                    visited[row - 1][i] = true;
                    q.push({row - 1, i});
                }
            }

            for (int i = 0; i < row; i++)
            {
                if (!visited[i][0] && arr[i][0] == '\0')
                {
                    visited[i][0] = true;
                    q.push({i, 0});
                }
                if (!visited[i][col - 1] && arr[i][col - 1] == '\0')
                {
                    visited[i][col - 1] = true;
                    q.push({i, col - 1});
                }
            }
            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                accessible[x][y] = true;
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col)
                    {
                        if (!visited[nx][ny] && arr[nx][ny] == '\0')
                        {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            // target인 지점 중에서 빈칸 연결인지 찾기
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (arr[i][j] == target)
                    {
                        bool acc = false;
                        if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
                        {
                            acc = true;
                        }
                        else
                        {
                            for (int k = 0; k < 4; k++)
                            {
                                int nx = i + dx[k];
                                int ny = j + dy[k];
                                // 외부와 연결됨 중요!!
                                if (nx < 0 || nx >= row || ny < 0 || ny >= col)
                                {
                                    acc = true;
                                    break;
                                }
                                if (accessible[nx][ny])
                                {
                                    acc = true;
                                    break;
                                }
                            }
                        }
                        if (acc)
                        {
                            arr[i][j] = '\0';
                        }
                    }
                }
            }
        }
        else if (req.size() > 1)
        {
            char target = req[0];
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (arr[i][j] == target)
                    {
                        arr[i][j] = '\0';
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != '\0')
            {
                answer++;
            }
        }
    }
    return answer;
}
