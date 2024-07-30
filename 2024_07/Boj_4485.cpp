#include <bits/stdc++.h>
using namespace std;

int arr[126][126];
int dist[126][126];
bool visited[126][126];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {
    -1,
    1,
    0,
    0};
vector<int> ansArr;
int main()
{
    int idx = 0;
    while (1)
    {
        idx++;

        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                cin >> arr[i][j];
                dist[i][j] = INT_MAX;
            }
        }

        // dist[i][j] 까지 왔을떄 최솟값을 다익스트라로!
        // 다익스트라 + 우선순위 큐로!
        // 현재까지 비용, x,y
        priority_queue<pair<int, pair<int, int>>> pq;
        // 우선순위큐는 내림차순이 기본이기에 반대로
        pq.push({-arr[0][0], {0, 0}});
        dist[0][0] = arr[0][0];
        while (!pq.empty())
        {
            int cost = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            // 네 방향으로 이동하기!
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    if (dist[nx][ny] > arr[nx][ny] + cost)
                    {
                        dist[nx][ny] = arr[nx][ny] + cost;
                        pq.push({-dist[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        ansArr.push_back(dist[n - 1][n - 1]);
    }
    for (int i = 0; i < ansArr.size(); i++)
    {
        cout << "Problem " << i + 1 << ":" << " " << ansArr[i] << endl;
    }
}