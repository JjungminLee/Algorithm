#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int visited[101][101];
vector<int> v;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    if (arr[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                    }
                    else if (arr[nx][ny] == 1)
                    {
                        arr[nx][ny] = 0;
                    }
                }
            }
        }
    }
}
int main()
{

    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (1)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    cnt++;
                }
            }
        }

        if (cnt == 0)
        {
            break;
        }
        else
        {
            memset(visited, 0, sizeof(visited));
            bfs(0, 0);

            v.push_back(cnt);
        }
    }
    cout << v.size() << endl;
    cout << v[v.size() - 1] << endl;
}