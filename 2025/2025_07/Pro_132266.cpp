#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<vector<int>> v(n + 1);
    priority_queue<int> pq;
    vector<int> dist(n + 1, 1e9);
    vector<int> answer;
    for (int i = 0; i < roads.size(); i++)
    {
        int a = roads[i][0];
        int b = roads[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    pq.push(destination);
    dist[destination] = 0;
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        for (int nextNode : v[cur])
        {
            if (dist[nextNode] > dist[cur] + 1)
            {
                dist[nextNode] = dist[cur] + 1;
                pq.push(nextNode);
            }
        }
    }

    for (int i = 0; i < sources.size(); i++)
    {
        if (dist[sources[i]] == 1e9)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(dist[sources[i]]);
        }
    }

    return answer;
}