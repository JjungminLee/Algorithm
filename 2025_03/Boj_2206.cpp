#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1001][1001];
int visited[2][1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool flag = false;
void bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;
    while (!q.empty())
    {

        int x, y, wall;
        tie(x, y, wall) = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1)
        {
            cout << visited[wall][x][y] << endl;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (visited[wall][nx][ny] == 0 && arr[nx][ny] == 0)
                {
                    visited[wall][nx][ny] = visited[wall][x][y] + 1;
                    q.push({nx, ny, wall});
                }
                else if (visited[wall][nx][ny] == 0 && arr[nx][ny] == 1 && wall == 0)
                {
                    visited[1][nx][ny] = visited[0][x][y] + 1;
                    q.push({nx, ny, 1});
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
    bfs();
}