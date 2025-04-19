#include <bits/stdc++.h>

using namespace std;
int parents[101];
int findParent(int a)
{
    if (parents[a] == a)
    {
        return a;
    }
    return parents[a] = findParent(parents[a]);
}

void unions(int a, int b)
{
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa > pb)
    {
        parents[pa] = pb;
    }
    else
    {
        parents[pb] = pa;
    }
}

bool isCycle(int a, int b)
{
    int pa = findParent(a);
    int pb = findParent(b);
    if (pa == pb)
    {
        return true;
    }
    return false;
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    // 비용 기준으로 정렬하고 크루스칼 돌리자!

    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < costs.size(); i++)
    {
        v.push_back({costs[i][2], {costs[i][0], costs[i][1]}});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++)
    {
        parents[i] = i;
    }

    for (int i = 0; i < v.size(); i++)
    {
        int cost = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;

        if (!isCycle(x, y))
        {

            unions(x, y);
            answer += cost;
        }
    }
    return answer;
}