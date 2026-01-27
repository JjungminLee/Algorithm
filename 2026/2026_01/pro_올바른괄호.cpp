#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (stk.empty())
            {
                return false;
            }
            else if (stk.top() == '(')
            {
                stk.pop();
            }
            else
            {
                stk.push(')');
            }
        }
    }

    if (!stk.empty())
    {
        return false;
    }

    return answer;
}