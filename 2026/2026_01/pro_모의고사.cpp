#include <bits/stdc++.h>
using namespace std;

vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int a1;
int a2;
int a3;

bool compares(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int size = answers.size();
    int v1Size = v1.size();
    int v2Size = v2.size();
    int v3Size = v3.size();

    for (int i = v1.size(); i <= size; i++)
    {
        v1.push_back(v1[i % v1Size]);
    }
    for (int i = v2.size(); i <= size; i++)
    {
        v2.push_back(v2[i % v2Size]);
    }
    for (int i = v3.size(); i <= size; i++)
    {
        v3.push_back(v3[i % v3Size]);
    }
    for (int i = 0; i < answers.size(); i++)
    {
        if (v1[i] == answers[i])
        {
            a1++;
        }
        if (v2[i] == answers[i])
        {
            a2++;
        }
        if (v3[i] == answers[i])
        {
            a3++;
        }
    }
    vector<pair<int, int>> v;
    v.push_back({a1, 1});
    v.push_back({a2, 2});
    v.push_back({a3, 3});
    sort(v.begin(), v.end(), compares);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }

    if (v[0].first == v[1].first && v[0].first == v[2].first)
    {
        answer.push_back(v[0].second);
        answer.push_back(v[1].second);
        answer.push_back(v[2].second);
        return answer;
    }
    else if (v[0].first == v[1].first)
    {
        answer.push_back(v[0].second);
        answer.push_back(v[1].second);
        return answer;
    }
    answer.push_back(v[0].second);
    return answer;
}