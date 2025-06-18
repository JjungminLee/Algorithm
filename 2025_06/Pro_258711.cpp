#include <bits/stdc++.h>

using namespace std;

map<int, pair<int, int>> mp;

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer;
    for (int i = 0; i < edges.size(); i++)
    {
        int start = edges[i][0];
        int end = edges[i][1];
        mp[start].second++;
        mp[end].first++;
    }
    int a = 0;         // 도넛
    int b = 0;         // 막대
    int c = 0;         // 8그래프
    int createIdx = 0; // 생성정점 번호
    int createOut = 0; // 생성 정점 나가는간선
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int inDegree = it->second.first;
        int outDegree = it->second.second;
        if (inDegree >= 1 && outDegree == 0)
        {
            b++;
        }
        if (inDegree >= 2 && outDegree == 2)
        {
            c++;
        }
        if (inDegree == 0 && outDegree >= 2)
        {
            createIdx = it->first;
            createOut = outDegree;
        }
    }
    a = createOut - (b + c);
    answer.push_back(createIdx);
    answer.push_back(a);
    answer.push_back(b);
    answer.push_back(c);
    return answer;
}