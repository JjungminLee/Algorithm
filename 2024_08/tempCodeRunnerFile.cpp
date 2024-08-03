#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1002][1002];
int dist[1002][1002];
bool visited[1002][1002];
int xCor, yCor;

int main()
{
    cin >> n;
    cin >> m;
    memset(arr, 0, sizeof(arr));
    memset(dist, 1000000, sizeof(dist));

    for (int i = 0; i < m; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        arr[x][y] = cost;
        dist[x][y] = cost;
    }
    cin >> xCor >> yCor;
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                dist[i][j] = min(dist[i][j], dist[i][j - 1] + arr[j - 1][j]);
            }
        }
    }

    cout << dist[xCor][yCor] << endl;
}
