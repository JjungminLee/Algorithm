#include <bits/stdc++.h>
using namespace std;
int n, m;
int dist[50001];
vector<pair<int, int>> arr[50001];
void dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // {거리,정점} -> 거리 순으로 짧은걸 우선순위큐에서 넣어야하기 때문
    pq.push({0, 1});
    dist[0] = 1;
    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
        for (auto a : arr[curr_node])
        {
            int next_edge = a.first;
            int next_dist = a.second;
            if (dist[next_edge] > curr_dist + next_dist)
            {
                dist[next_edge] = curr_dist + next_dist;
                pq.push({curr_dist + next_dist, next_edge});
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