#include <bits/stdc++.h>

using namespace std;

#define MAX (60)

char maps[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<string> storage, vector<string> requests)
{
    int answer = 0;
    int n = storage.size();
    int m = storage[0].size();

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            maps[i][j] = '.';

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            maps[i][j] = storage[i - 1][j - 1];
        }
    }

    for (int i = 0; i < requests.size(); i++)
    {
        string str = requests[i];
        if (str.size() > 1)
        {
            char ch = str[0];
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= m; k++)
                {
                    if (maps[j][k] == ch)
                    {
                        maps[j][k] = '.';
                    }
                }
            }
        }
        else
        {
            bool visited[MAX][MAX] = {
                false,
            };
            queue<pair<int, int>> q;
            q.push({0, 0});
            visited[0][0] = true;

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                int cx = cur.first;
                int cy = cur.second;

                for (int i = 0; i < 4; i++)
                {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1)
                    {
                        if (!visited[nx][ny])
                        {
                            if (maps[nx][ny] == str[0])
                            {
                                maps[nx][ny] = '.';
                                visited[nx][ny] = true;
                            }
                            else if (maps[nx][ny] == '.')
                            {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (maps[i][j] != '.')
            {
                answer++;
            }
        }
        cout << endl;
    }
    return answer;
}
