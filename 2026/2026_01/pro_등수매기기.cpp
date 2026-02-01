#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<vector<int>> score)
{
    vector<int> answer;
    vector<int> v;
    vector<pair<int, int>> sv;
    for (int i = 0; i < score.size(); i++)
    {
        int a = score[i][0];
        int b = score[i][1];
        v.push_back(a + b);
    }
    for (int i = 0; i < v.size(); i++)
    {
        sv.push_back({v[i], 0});
    }
    sort(sv.begin(), sv.end(), greater<>());
    int rank = 1;
    for (int i = 0; i < sv.size(); i++)
    {
        int cnt = 0;
        if (sv[i].second != 0)
            continue;

        sv[i].second = rank;
        for (int j = i + 1; j < sv.size(); j++)
        {
            if (sv[j].first == sv[i].first)
            {
                sv[j].second = rank;
                cnt++;
            }
        }
        rank += (cnt + 1);
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < sv.size(); j++)
        {
            if (v[i] == sv[j].first)
            {
                answer.push_back(sv[j].second);
                break;
            }
        }
    }
    return answer;
}