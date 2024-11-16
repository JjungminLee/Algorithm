#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<string, int>> v;
unordered_map<string, int> freqMap;

bool compare(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        if (a.first.size() == b.first.size())
        {
            return a.first < b.first;
        }
        return a.first.size() > b.first.size();
    }
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s.length() >= m)
        {
            freqMap[s]++;
        }
    }
    for (auto a : freqMap)
    {
        v.push_back({a.first, a.second});
    }
    // 등장 횟수 내림차순 정렬

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << "\n";
    }
}