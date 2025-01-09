#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans;
int visited[1001][1001];
int totalCnt;
int ripeCnt;
// 총 토마토 수 , 다 익은 토마토 수 감지
// 현재 레벨의 큐는 전부 끝내버려야함
// 현재 레벨의 큐의 사이즈를 구하고 반복문 돌려서 전부 pop

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != -1)
            {
                totalCnt++;
            }
            if (arr[i][j] == 1)
            {
                q.push({i, j});
                visited[i][j] = true;
                ripeCnt++;
            }
        }
    }
    int days = -1;
    if (ripeCnt == totalCnt)
    {
        cout << 0 << endl;
        return;
    }
    while (!q.empty())
    {
        int size = q.size();
        // 현재 레벨의 큐는 바로 다 비워야함
        for (int r = 0; r < size; r++)
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
                    if (arr[nx][ny] == 0 && !visited[nx][ny])
                    {
                        arr[nx][ny] = 1;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        ripeCnt++;
                    }
                }
            }
        }
        days++;
    }
    if (totalCnt == ripeCnt)
    {
        cout << days << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    bfs();
}