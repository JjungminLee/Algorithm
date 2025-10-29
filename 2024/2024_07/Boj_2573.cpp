#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int arr[301][301];
int temp[301][301];
int ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

//  일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다

// 빙산 줄이기
// 복사된 배열 사용해야!
// 굳이 bfs로 할 필요는 없음 -> 어차피 인접배열 탐색이 아닌 동서남북으로 빙하가 있는지 탐색하는 것이기 때문!

void melt()
{
    memcpy(temp, arr, sizeof(arr));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] > 0)
            {
                int decrease = 0;

                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (arr[nx][ny] == 0)
                    {
                        decrease++;
                    }
                }
                temp[i][j] = max(arr[i][j] - decrease, 0);
            }
        }
    }
    memcpy(arr, temp, sizeof(temp));
}

// bfs로 덩어리 계산하기

int findArea(int x, int y, bool visited[301][301])
{
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        int px = q.front().first;
        int py = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = px + dx[i];
            int ny = py + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && arr[nx][ny] > 0)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }
    return cnt;
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
        bool visited[301][301] = {
            0,
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && arr[i][j] > 0)
                {
                    // visited[i][j] = true;
                    int areaCnt = findArea(i, j, visited);
                    if (areaCnt >= 1)
                    {
                        cnt++;
                    }
                }
            }
        }
        if (cnt >= 2)
        {
            break;
        }
        else if (cnt == 0)
        {
            ans = 0;
            break;
        }
        else
        {
            melt();
            ans++;
        }
    }
    cout << ans << endl;
}