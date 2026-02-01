#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;

bool compares(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    for (int i = 0; i < routes.size(); i++)
    {
        int a = routes[i][0];
        int b = routes[i][1];
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), compares);
    int camera = v[0].second;
    answer++;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first > camera)
        {
            answer++;
            camera = v[i].second;
        }
    }
    return answer;
}