#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

bool compares(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second > b.second;
}
vector<int> solution(string s)
{
    vector<int> answer;
    vector<pair<int, int>> v;
    string str = "";
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{' || s[i] == '}')
        {
            continue;
        }
        else if (s[i] == ',')
        {
            mp[str]++;
            str = "";
        }
        else
        {
            str += s[i];
        }
    }
    if (str != "")
    {
        mp[str]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        v.push_back({stoi(it->first), it->second});
    }
    sort(v.begin(), v.end(), compares);

    for (int i = 0; i < v.size(); i++)
    {
        answer.push_back(v[i].first);
    }
    return answer;
}