#include <bits/stdc++.h>

using namespace std;
string target[4] = {"aya", "ye", "woo", "ma"};

bool check(string s)
{
    string prev = " ";
    while (!s.empty())
    {
        bool ok = false;
        for (string t : target)
        {
            if (s.rfind(t, 0) == 0 && prev != t)
            {
                ok = true;
                prev = t;
                s.erase(0, t.size());
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}

int solution(vector<string> babbling)
{
    int answer = 0;
    for (string s : babbling)
    {
        if (check(s))
        {
            answer++;
        }
    }

    return answer;
}