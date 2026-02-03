#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    map<char, int> mp;
    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        {
            char ch = keymap[i][j];
            int press = j + 1;
            if (!mp.count(ch))
            {
                mp[ch] = press;
            }
            else
            {
                mp[ch] = min(mp[ch], press);
            }
        }
    }
    for (int i = 0; i < targets.size(); i++)
    {
        int cnt = 0;
        bool flag = true;
        for (int j = 0; j < targets[i].size(); j++)
        {
            char ch = targets[i][j];
            if (!mp.count(ch))
            {
                flag = false;
                break;
            }
            cnt += mp[ch];
        }
        if (flag)
        {
            answer.push_back(cnt);
        }
        else
        {
            answer.push_back(-1);
        }
    }
    return answer;
}