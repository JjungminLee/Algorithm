#include <bits/stdc++.h>

using namespace std;

bool compares(pair<double, int> a, pair<double, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    vector<pair<double, int>> v;
    int size = stages.size();
    map<int, int> mp;
    for (int i = 0; i < stages.size(); i++)
    {
        mp[stages[i]]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (size == 0)
        {
            v.push_back({0, i});
        }
        else
        {
            v.push_back({mp[i] / double(size), i});
            size -= mp[i];
        }
    }

    sort(v.begin(), v.end(), compares);
    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].second);
    }

    return answer;
}