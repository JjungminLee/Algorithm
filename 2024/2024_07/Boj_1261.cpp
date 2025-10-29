#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long arr[101][101];
bool visited[101][101];
long long dist[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main()
{
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            dist[i][j] = LLONG_MAX;
        }
    }

    priority_queue<tuple<long long, long long, long long>> pq;
    dist[0][0] = 0;
    pq.push({-dist[0][0], 0, 0});

    while (!pq.empty())
    {
        long long cost, x, y;
        tie(cost, x, y) = pq.top();
        cost *= -1;

        pq.pop();
        // 이미 처리된 코드이면 skip
        if (visited[x][y])
        {
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (dist[nx][ny] == LLONG_MAX)
                {
                    visited[x][y] = true;
                    if (arr[nx][ny] == 0)
                    {
                        dist[nx][ny] = min(dist[nx][ny], cost);
                        pq.push({-dist[nx][ny], nx, ny});
                    }
                    else if (arr[nx][ny] == 1)
                    {
                        arr[nx][ny] = 0;

                        dist[nx][ny] = min(dist[nx][ny], cost + 1);
                        pq.push({-dist[nx][ny], nx, ny});
                    }
                }
            }
        }
    }
    cout << dist[m - 1][n - 1] << endl;
}