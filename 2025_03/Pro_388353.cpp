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

            // 경계에 있는 빈 칸들부터 시작
            for (int i = 0; i < row; i++)
            {
                if (arr[i][0] == '\0' && !visited[i][0])
                {
                    visited[i][0] = true;
                    q.push({i, 0});
                }
                if (arr[i][col - 1] == '\0' && !visited[i][col - 1])
                {
                    visited[i][col - 1] = true;
                    q.push({i, col - 1});
                }
            }
            for (int j = 0; j < col; j++)
            {
                if (arr[0][j] == '\0' && !visited[0][j])
                {
                    visited[0][j] = true;
                    q.push({0, j});
                }
                if (arr[row - 1][j] == '\0' && !visited[row - 1][j])
                {
                    visited[row - 1][j] = true;
                    q.push({row - 1, j});
                }
            }

            while (!q.empty())
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                accessible[x][y] = true;
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && arr[nx][ny] == '\0')
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (arr[i][j] == target)
                    {
                        bool acc = false;
                        // 경계에 위치하면 바로 접근 가능
                        if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
                        {
                            acc = true;
                        }
                        else
                        {
                            // 인접한 셀 중 하나라도 외부와 연결된 빈 영역이면 접근 가능
                            for (int k = 0; k < 4; k++)
                            {
                                int nx = i + dx[k], ny = j + dy[k];
                                // 인접 셀이 격자 밖이면 외부와 연결된 것이므로 접근 가능
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
