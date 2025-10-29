#include <bits/stdc++.h>
using namespace std;
int n;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
bool visited[301][301];
int main()
{
    cin >> n;
    while (n--)
    {
        int ans = 1e9;
        int num;
        cin >> num;
        memset(visited, 0, sizeof(visited));
        int startX;
        int startY;
        int endX;
        int endY;
        cin >> startX >> startY;
        cin >> endX >> endY;
        visited[startX][startY] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {startX, startY}});
        bool flag = false;
        int cnt = 0;
        while (!q.empty())
        {
            cnt = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            if (x == endX && y == endY)
            {
                flag = true;
                ans = min(ans, cnt);

                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < num && ny >= 0 && ny < num)
                {
                    if (!visited[nx][ny])
                    {

                        visited[nx][ny] = true;
                        q.push({cnt + 1, {nx, ny}});
                    }
                }
            }
        }
        if (flag)
        {

            cout << ans - 1 << endl;
        }
        else
        {

            cout << cnt << endl;
        }
    }
}