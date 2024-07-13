#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[9][9];
int visited[9][9];
int tempArr[9][9];
int ans = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {
    0,
    0,
    -1,
    1,
};
void bfs()
{
    memcpy(tempArr, arr, sizeof(arr));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tempArr[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

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
                if (tempArr[nx][ny] == 0)
                {
                    tempArr[nx][ny] = 2;

                    q.push({nx, ny});
                }
            }
        }
    }
}
void makeColumn(int cnt)
{
    if (cnt == 3)
    {
        int temp = 0;
        bfs();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (tempArr[i][j] == 0)
                {
                    temp++;
                }
            }
        }
        ans = max(ans, temp);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0 && !visited[i][j])
            {
                arr[i][j] = 1;
                visited[i][j] = true;
                makeColumn(cnt + 1);
                arr[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
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
    makeColumn(0);
    cout << ans << endl;
}