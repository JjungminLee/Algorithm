#include <bits/stdc++.h>

using namespace std;

bool check(string str)
{
    vector<string> v;
    int mode = 1;
    int answer = 0;

    string s = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            if (!s.empty())
            {
                v.push_back(s);
                s = "";
            }
        }
        else if (str[i] == '+')
        {
            v.push_back("+");
        }
        else if (str[i] == '-' && str[i + 1] == ' ')
        {
            v.push_back("-");
        }
        else if (str[i] == '=')
        {
            v.push_back("=");
        }
        else
        {
            s += str[i];
        }
    }
    if (s != "")
    {
        v.push_back(s);
    }

    for (int i = 0; i < v.size() - 2; i++)
    {
        if (v[i] == "-")
        {
            mode = -1;
        }
        else if (v[i] == "+")
        {
            mode = 1;
        }
        else
        {
            int num = stoi(v[i]);
            if (mode == 1)
            {
                answer += num;
            }
            else
            {
                answer -= num;
            }
        }
    }
    int lastNum = stoi(v[v.size() - 1]);

    return lastNum == answer;
}
vector<string> solution(vector<string> quiz)
{
    vector<string> answer;
    for (int i = 0; i < quiz.size(); i++)
    {
        string str = quiz[i];

        if (check(str))
        {
            answer.push_back("O");
        }
        else
        {
            answer.push_back("X");
        }
    }
    return answer;
}