#include <bits/stdc++.h>

using namespace std;
// 장르 이름, 노래
map<string, int> mp;
// vector<재생횟수, 고유번호>
map<string, vector<pair<int, int>>> mp2;
vector<pair<string, int>> v;

bool compares(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}

bool compares2(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    int n = genres.size();

    for (int i = 0; i < n; i++)
    {
        mp[genres[i]] += plays[i];
        mp2[genres[i]].push_back({plays[i], i});
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        v.push_back({it->first, it->second});
    }
    sort(v.begin(), v.end(), compares2);

    for (auto it = mp2.begin(); it != mp2.end(); it++)
    {
        sort(it->second.begin(), it->second.end(), compares);
    }

    for (int i = 0; i < v.size(); i++)
    {
        string g = v[i].first;
        vector<pair<int, int>> v2 = mp2[g];
        int cnt = min(2, (int)v2.size());
        // v2의 사이즈가 2미만이면 out of range 터짐
        for (int i = 0; i < cnt; i++)
        {
            answer.push_back(v2[i].second);
        }
    }
    return answer;
}