#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;

bool comparators(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int solution(vector<vector<int>> targets)
{
    int answer = 0;
    for (int i = 0; i < targets.size(); i++)
    {
        v.push_back({targets[i][0], targets[i][1]});
    }
    sort(v.begin(), v.end(), comparators);
    double cur = v[0].second - 0.1;

    for (int i = 1; i < v.size(); i++)
    {
        if (cur <= v[i].first || cur >= v[i].second)
        {
            answer++;
            cur = v[i].second - 0.1;
        }
    }

    return answer + 1;
}