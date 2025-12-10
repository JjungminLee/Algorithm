#include <bits/stdc++.h>

using namespace std;

int intensity[50005];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<int> answer;
    vector<pair<int, int>> v[50005];
    bool isGate[50005] = {
        false,
    };
    bool isSummit[50005] = {
        false,
    };
    int summitCnt = 0;

    for (int i = 0; i < 50005; i++)
    {
        intensity[i] = INT_MAX;
    }
    for (int g : gates)
    {
        isGate[g] = true;
    }
    for (int s : summits)
    {
        isSummit[s] = true;
    }
    for (int i = 0; i < paths.size(); i++)
    {
        int a = paths[i][0];
        int b = paths[i][1];
        int c = paths[i][2];
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    // 작은게 앞으로 오게
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int g : gates)
    {
        pq.push({0, g});
        intensity[g] = 0;
    }

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int cDist = p.first;
        int cIdx = p.second;

        if (cDist > intensity[cIdx])
            continue;
        if (isSummit[cIdx])
            continue;
        for (auto next : v[cIdx])
        {
            if (isGate[next.second])
                continue;
            int newIntensity = max(intensity[cIdx], next.first);
            if (intensity[next.second] > newIntensity)
            {
                intensity[next.second] = newIntensity;
                pq.push({intensity[next.second], next.second});
            }
        }
    }
    int minNum = INT_MAX;
    int minIdx = INT_MAX;

    for (int s : summits)
    {
        if (intensity[s] < minNum)
        {
            minNum = intensity[s];
            minIdx = s;
        }
        else if (intensity[s] == minNum && s < minIdx)
        {
            minIdx = s;
        }
    }
    answer.push_back(minIdx);
    answer.push_back(minNum);
    return answer;
}