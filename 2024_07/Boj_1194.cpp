#include <bits/stdc++.h>
using namespace std;

int arr[52][52];
int n, m;
int ans = 300000000;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int startX;
int startY;
bool keys[26] = {false};

void bfs(int x, int y, int cnt)
{
    queue<tuple<int, int, int>> q;
    vector<char> v;
    int visited[52][52] = {false};
    visited[x][y] = true;
    q.push({x, y, cnt});

    while (!q.empty())
    {
        int x, y, count;
        tie(x, y, count) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && cnt <= ans)
            {
                visited[nx][ny] = true;

                if (arr[nx][ny] == '1' && count + 1 < ans)
                {
                    ans = count + 1;
                    return;
                }
                if (arr[nx][ny] == '0' || arr[nx][ny] == '.')
                {
                    if (ans > count + 1)
                    {
                        q.push({nx, ny, count + 1});
                    }
                }
                else if ('A' <= arr[nx][ny] && arr[nx][ny] <= 'F')
                {
                    if (keys[arr[nx][ny] - 'A'])
                    {
                        if (ans > count + 1)
                        {
                            q.push({nx, ny, count + 1});
                        }
                    }
                }
                else if ('a' <= arr[nx][ny] && arr[nx][ny] <= 'f')
                {
                    if (keys[arr[nx][ny] - 'a'])
                    {
                        if (ans > count + 1)
                        {
                            q.push({nx, ny, count + 1});
                        }
                    }
                    else
                    {
                        keys[arr[nx][ny] - 'a'] = true;
                        bfs(nx, ny, count + 1);
                        keys[arr[nx][ny] - 'a'] = false;
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char input;
            cin >> input;
            arr[i][j] = input;
            if (arr[i][j] == '0')
            {
                startX = i;
                startY = j;
            }
        }
    }

    bfs(startX, startY, 0);
    if (ans == 300000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
