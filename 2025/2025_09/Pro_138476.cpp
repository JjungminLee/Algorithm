#include <bits/stdc++.h>

using namespace std;
map<int, int> mp;

bool compares(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    for (int num : tangerine)
    {
        mp[num]++;
    }
    vector<pair<int, int>> v;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        v.push_back({it->first, it->second});
    }
    sort(v.begin(), v.end(), compares);

    int idx = 0;
    while (k > 0 && idx < v.size())
    {
        k -= v[idx].second;
        idx++;
        answer++;
    }

    return answer;
}