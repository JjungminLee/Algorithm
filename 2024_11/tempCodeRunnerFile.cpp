#include <bits/stdc++.h>
using namespace std;
int n;
char arr[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = INT_MAX;
bool visited[50][50];
void bfs()
{
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < 4; i++)
    {
        int x = dx[i];
        int y = dy[i];
        visited[x][y] = true;
        if (x >= 0 && x < n && y >= 0 && y < n)
        {
            if (arr[x][y] == '1')
            {
                q.push({{x, y}, 0});
            }
            else
            { // 검은벽을 뚫는 경우
                q.push({{x, y}, 1});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if (x == n - 1 && y == n - 1)
        {
            ans = min(ans, cnt);
            continue;
        }
        else
        {
            visited[x][y] = true;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (arr[nx][ny] == '1' && !visited[nx][ny])
                {
                    q.push({{nx, ny}, cnt});
                }
                else if (arr[nx][ny] == '0' && !visited[nx][ny])
                {
                    if (cnt + 1 < ans)
                    {
                        q.push({{nx, ny}, cnt + 1});
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j];
        }
    }

    bfs();
    cout << ans << endl;
}