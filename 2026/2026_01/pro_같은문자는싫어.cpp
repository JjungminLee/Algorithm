#include <bits/stdc++.h>

using namespace std;

stack<int> stk;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        if (stk.empty())
        {
            stk.push(arr[i]);
        }
        else
        {
            if (stk.top() != arr[i])
            {
                stk.push(arr[i]);
            }
        }
    }

    vector<int> v;
    while (!stk.empty())
    {
        v.push_back(stk.top());
        stk.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        answer.push_back(v[i]);
    }

    return answer;
}