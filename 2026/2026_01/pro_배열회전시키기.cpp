#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers, string direction)
{
    vector<int> answer;
    deque<int> q;
    int n = numbers.size();
    if (direction == "right")
    {
        q.push_back(numbers[n - 1]);
        for (int i = 0; i < n - 1; i++)
        {
            q.push_back(numbers[i]);
        }
        while (!q.empty())
        {
            int num = q.front();
            answer.push_back(num);
            q.pop_front();
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            q.push_back(numbers[i]);
        }
        q.push_back(numbers[0]);

        while (!q.empty())
        {
            int num = q.front();
            answer.push_back(num);
            q.pop_front();
        }
    }
    return answer;
}