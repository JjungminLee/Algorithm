#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;
    int n = progresses.size();
    for (int i = 0; i < n; i++)
    {
        int num = 100 - progresses[i];
        int portion = (num + speeds[i] - 1) / speeds[i];
        q.push(portion);
    }
    int cnt = 0;
    int prev = -1;
    while (!q.empty())
    {
        if (prev == -1)
        {
            cnt++;
            prev = q.front();
            q.pop();
        }
        else if (prev >= q.front())
        {
            cnt++;
            // 여기서 prev는 유지
            q.pop();
        }
        else if (prev < q.front())
        {
            answer.push_back(cnt);
            cnt = 1;
            prev = q.front();
            q.pop();
        }
    }
    if (cnt > 0)
    {
        answer.push_back(cnt);
    }

    return answer;
}