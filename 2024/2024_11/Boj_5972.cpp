#include <bits/stdc++.h>
using namespace std;

/*
인접리스트로 만드는 방법
우선순위큐 다익스트라
 */

int n, m;
vector<pair<int, int>> arr[50001];
int dist[50001];

void dijkstra()
{
    // 거리가 짧은 순으로 다익스트라?
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // {거리,정점}
    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        // 거리
        int curr_dist = pq.top().first;
        // 정점
        int curr_node = pq.top().second;

        pq.pop();
        // 현재 거리가 누적거리보다 크면 넘긴다
        if (curr_dist > dist[curr_node])
        {
            continue;
        }
        for (auto a : arr[curr_node])
        {
            int next_node = a.first;
            int distance = a.second;
            if (dist[next_node] > curr_dist + distance)
            {
                dist[next_node] = distance + curr_dist;
                pq.push({distance + curr_dist, next_node});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arr[x].push_back({y, z});
        arr[y].push_back({x, z});
    }

    dijkstra();
    cout << dist[n] << endl;
}