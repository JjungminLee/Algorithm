#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, greater<>> pq;
vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    for (int num : score)
    {
        if (pq.size() == 0)
        {
            pq.push(num);
        }
        else if (pq.size() < k)
        {
            pq.push(num);
        }
        else if (pq.size() >= k && pq.top() <= num)
        {
            pq.pop();
            pq.push(num);
        }

        answer.push_back(pq.top());
    }
    return answer;
}