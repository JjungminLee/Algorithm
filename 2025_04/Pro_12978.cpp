#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[51];
int dist[51];

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;

    for (int i = 0; i < road.size(); i++)
    {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= N; i++)
    {
        dist[i] = 1e9;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 거리,노드

    pq.push({0, 1});
    dist[1] = 0;
    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        // 이미 더 짧은 경로로 방문한적이 있었다면 무시
        if (d > dist[node])
        {
            continue;
        }
        for (auto [nextNode, cost] : v[node])
        {
            if (dist[nextNode] > dist[node] + cost)
            {
                dist[nextNode] = dist[node] + cost;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
        {
            answer++;
        }
    }

    return answer;
}