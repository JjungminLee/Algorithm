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
        int ans = INT_MAX;
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
        priority_queue<tuple<int, int, int>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            int x, y, z;
            tie(x, y, z) = pq.top();
            pq.pop();
        }

        ansArr.push_back(ans);
    }
    for (int i = 0; i < ansArr.size(); i++)
    {
        cout << "Problem " << i + 1 << ":" << " " << ansArr[i] << endl;
    }
}