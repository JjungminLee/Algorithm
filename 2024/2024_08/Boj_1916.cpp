#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> graph[10001];
int dist[10001];
int xCor, yCor;
int main()
{
    priority_queue<pair<int, int>> pq;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        graph[x].push_back({y, cost});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    cin >> xCor >> yCor;
    dist[xCor] = 0;
    pq.push({0, xCor});
    while (!pq.empty())
    {
        int curr, cost;
        cost = pq.top().first;
        curr = pq.top().second;
        pq.pop();
        cost *= -1;
        if (dist[curr] < cost)
        {
            continue;
        }
        for (int i = 0; i < graph[curr].size(); i++)
        {
            int nCost = cost + graph[curr][i].second;
            if (nCost < dist[graph[curr][i].first])
            {
                dist[graph[curr][i].first] = nCost;
                pq.push({-nCost, graph[curr][i].first});
            }
        }
    }
    cout << dist[yCor] << endl;
}