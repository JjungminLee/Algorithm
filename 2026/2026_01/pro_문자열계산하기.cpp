#include <bits/stdc++.h>

using namespace std;

int solution(string my_string)
{
    int answer = 0;
    int curMode = 1;
    vector<string> v;
    string str = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        char ch = my_string[i];
        if (ch == ' ')
        {
            if (!str.empty())
            {
                v.push_back(str);
                str = "";
            }
        }
        else if (ch == '+')
        {
            v.push_back("+");
        }
        else if (ch == '-')
        {
            v.push_back("-");
        }
        else
        {
            str += ch;
            if (i == my_string.size() - 1)
            {
                v.push_back(str);
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "+")
        {
            curMode = 1;
        }
        else if (v[i] == "-")
        {
            curMode = -1;
        }
        else
        {
            int num = stoi(v[i]);
            if (curMode == 1)
            {
                answer += num;
            }
            else
            {
                answer -= num;
            }
        }
    }
    return answer;
}