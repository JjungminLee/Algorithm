#include <bits/stdc++.h>
using namespace std;

int n, m;
int maps[101];
int visited[101];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    while (!q.empty())
    {
        int loc = q.front().first;
        int count = q.front().second;
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            int nx = loc + i;
            if (nx == 100)
            {
                cout << count + 1 << endl;
                return;
            }
            else if (nx < 100)
            {
                if (maps[nx] != 0)
                {
                    nx = maps[nx];
                }
                if (!visited[nx])
                {
                    visited[nx] = true;
                    q.push({nx, count + 1});
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
        int x, y;
        cin >> x;
        cin >> y;
        maps[x] = y;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
        maps[x] = y;
    }
    bfs();
}