#include <bits/stdc++.h>
using namespace std;
int dx[4] = {
    -1,
    1,
    0,
    0,
};
int dy[4] = {0, 0, -1, 1};
int n, m;
char arr[21][21];
bool visited[21][21][21][21];
int ans = 1e9;
struct State
{
    int x1, y1, x2, y2, cnt;
};
vector<pair<int, int>> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j];
            if (arr[i][j] == 'o')
            {
                v.push_back({i, j});
            }
        }
    }

    queue<State> q;
    q.push({v[0].first, v[0].second, v[1].first, v[1].second, 0});
    visited[v[0].first][v[0].second][v[1].first][v[1].second] = true;
    while (!q.empty())
    {
        State state = q.front();
        int x1 = state.x1;
        int y1 = state.y1;
        int x2 = state.x2;
        int y2 = state.y2;
        int cnt = state.cnt;
        q.pop();
        if (cnt >= 10)
        {
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];
            int outOfRange = 0;
            if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= m)
            {
                outOfRange++;
            }

            if (nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m)
            {
                outOfRange++;
            }
            if (outOfRange == 2)
            {
                continue;
            }
            else if (outOfRange == 1)
            {
                ans = min(ans, cnt + 1);
                cout << ans << endl;
                return 0;
            }
            else if (outOfRange == 0)
            {
                if (arr[nx1][ny1] != '#' && arr[nx2][ny2] != '#')
                {
                    if (!visited[nx1][ny1][nx2][ny2])
                    {
                        q.push({nx1, ny1, nx2, ny2, cnt + 1});
                        visited[nx1][ny1][nx2][ny2] = true;
                    }
                }
                else if (arr[nx1][ny1] != '#' && arr[nx2][ny2] == '#')
                {
                    if (!visited[nx1][ny1][x2][y2])
                    {
                        visited[nx1][ny1][x2][y2] = true;
                        q.push({nx1, ny1, x2, y2, cnt + 1});
                    }
                }
                else if (arr[nx1][ny1] == '#' && arr[nx2][ny2] != '#')
                {
                    if (!visited[x1][y1][nx2][ny2])
                    {
                        visited[x1][y1][nx2][ny2] = true;
                        q.push({x1, y1, nx2, ny2, cnt + 1});
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}