#include <bits/stdc++.h>

using namespace std;
string target[4] = {"aya", "ye", "woo", "ma"};

bool check(string s)
{
    while (!s.empty())
    {
        bool ok = false;
        for (string t : target)
        {
            // 앞에서부터 일치하는지
            if (s.rfind(t, 0) == 0)
            {
                s.erase(0, t.size());
                ok = true;
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
    for (string str : babbling)
    {
        if (check(str))
        {
            answer++;
        }
    }
    return answer;
}