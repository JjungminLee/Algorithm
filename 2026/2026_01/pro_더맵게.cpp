#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;

    for (int num : scoville)
    {
        pq.push(num);
    }

    while (pq.size() >= 2 && pq.top() < K)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int val = a + (b * 2);
        pq.push(val);
        answer++;
    }
    if (!pq.empty() && pq.top() >= K)
        return answer;
    return -1;
}