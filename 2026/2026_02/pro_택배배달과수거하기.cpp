#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    stack<pair<int, int>> dstack;
    stack<pair<int, int>> pstack;

    for (int i = 0; i < deliveries.size(); i++)
    {
        if (deliveries[i] > 0)
        {
            dstack.push({i + 1, deliveries[i]});
        }
    }

    for (int i = 0; i < pickups.size(); i++)
    {
        if (pickups[i] > 0)
        {
            pstack.push({i + 1, pickups[i]});
        }
    }

    while (!dstack.empty() || !pstack.empty())
    {
        // 현재 턴에서 갈수 있는 가장 먼기리
        int maxDist = 0;
        if (!dstack.empty())
        {
            maxDist = max(maxDist, dstack.top().first);
        }
        if (!pstack.empty())
        {
            maxDist = max(maxDist, pstack.top().first);
        }
        answer += (maxDist * 2);
        int dCap = cap;
        while (!dstack.empty() && dCap > 0)
        {
            auto dcur = dstack.top();
            dstack.pop();
            if (dcur.second <= dCap)
            {
                dCap -= dcur.second;
            }
            else
            {
                dstack.push({dcur.first, dcur.second - dCap});
                dCap = 0;
            }
        }

        int pCap = cap;
        while (!pstack.empty() && pCap > 0)
        {
            auto pcur = pstack.top();
            pstack.pop();
            if (pcur.second <= pCap)
            {
                pCap -= pcur.second;
            }
            else
            {
                pstack.push({pcur.first, pcur.second - pCap});
                pCap = 0;
            }
        }
    }

    return answer;
}