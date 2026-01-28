#include <bits/stdc++.h>

using namespace std;
queue<pair<int, char>> q;
priority_queue<int> pq;
int solution(vector<int> priorities, int location)
{
    int answer = 0;
    vector<pair<int, char>> v;
    for (int i = 0; i < priorities.size(); i++)
    {
        char ch = 'A' + i;
        q.push({priorities[i], ch});
        pq.push(priorities[i]);
    }
    while (!q.empty())
    {
        pair<int, char> cur = q.front();
        if (cur.first < pq.top())
        {
            q.pop();
            q.push(cur);
        }
        else
        {
            v.push_back(cur);
            pq.pop();
            q.pop();
        }
    }
    char target = 'A' + location;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == target)
        {
            answer = i + 1;
        }
    }
    return answer;
}