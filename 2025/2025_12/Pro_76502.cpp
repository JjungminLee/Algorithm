#include <bits/stdc++.h>

using namespace std;

bool findCorrectStr(string s)
{
    stack<char> stk;
    for (char ch : s)
    {
        if (ch == '[' || ch == '(' || ch == '{')
        {
            stk.push(ch);
        }
        else
        {
            if (stk.size() == 0)
            {
                return false;
            }
            else
            {
                if (ch == ']' && stk.top() == '[')
                {
                    stk.pop();
                }
                else if (ch == ')' && stk.top() == '(')
                {
                    stk.pop();
                }
                else if (ch == '}' && stk.top() == '{')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    if (stk.size() == 0)
    {
        return true;
    }
    return false;
}

int solution(string s)
{
    int answer = 0;
    int x = s.size();
    int size = s.size();

    while (1)
    {
        if (x == 0)
        {
            break;
        }
        string temp = "";
        for (int i = 1; i < s.size(); i++)
        {
            temp += s[i];
        }
        temp += s[0];
        if (findCorrectStr(temp))
        {
            answer++;
        }
        s = temp;
        x--;
    }
    return answer;
}