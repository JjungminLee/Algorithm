#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works)
{
    long long answer = 0;
    priority_queue<int> pq;
    for (int num : works)
    {
        pq.push(num);
    }

    while (!pq.empty() && n > 0)
    {
        int num = pq.top();
        pq.pop();
        if (num > 0)
        {
            pq.push(num - 1);
        }
        n--;
    }

    while (!pq.empty())
    {
        int num = pq.top();

        answer += (num * num);
        pq.pop();
    }
    return answer;
}