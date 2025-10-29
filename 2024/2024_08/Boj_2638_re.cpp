#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[101][101];
int ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void findInnerAir()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    bool visited[101][101] = {
        false,
    };
    visited[0][0] = true;
    arr[0][0] = 3;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && arr[nx][ny] == 0)
                {
                    arr[nx][ny] = 3;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}
void melt()
{
    findInnerAir();

    int temp[101][101];
    memcpy(temp, arr, sizeof(arr));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (arr[nx][ny] == 3)
                    {

                        cnt++;
                    }
                }
                if (cnt >= 2)
                {
                    temp[i][j] = 0;
                }
            }
        }
    }
    memcpy(arr, temp, sizeof(temp));
}
int main()
{
    cin >> n >> m;
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
                else if (arr[i][j] == 3)
                {
                    arr[i][j] = 0;
                }
            }
        }
        if (cnt == 0)
        {
            break;
        }
        melt();
        ans++;
    }
    cout << ans << endl;
}