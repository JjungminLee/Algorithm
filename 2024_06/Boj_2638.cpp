#include <bits/stdc++.h>
using namespace std;

int arr[110][110];
bool visited[110][110];
int times = 0;
vector<int> v;

void bfs(int n, int m)
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
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
    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                temp++;
            }
        }
    }
    v.push_back(temp);

    while (true)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            break;
        }
        // visited 배열 초기화
        memset(visited, false, sizeof(visited));
        bfs(n, m);

        times++;
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    temp++;
                }
            }
        }
        v.push_back(temp);
    }

    cout << times << endl;
    cout << v[times - 1] << endl;

    return 0;
}
