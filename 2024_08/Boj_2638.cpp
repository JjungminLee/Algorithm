#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans;
// 외부공기, 내부공기 구별
// 외부공기들만 bfs로 묶어주기
void findInnerAir()
{
    queue<pair<int, int>> q;
    bool visited[101][101] = {
        false,
    };
    q.push({0, 0});
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
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    arr[nx][ny] = 3;
                }
            }
        }
    }
}
void melt()
{
    queue<pair<int, int>> q;
    int temp[101][101];
    memcpy(temp, arr, sizeof(arr));

    findInnerAir();
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
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                    {
                        if (arr[nx][ny] == 3)
                        {
                            cnt++;
                        }
                    }
                }
                if (cnt >= 2)
                {
                    temp[i][j] = 0;
                }
            }
        }
    }
    memcpy(arr, temp, sizeof(arr));
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
                if (arr[i][j] == 3)
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