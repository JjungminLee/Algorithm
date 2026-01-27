#include <bits/stdc++.h>

using namespace std;
vector<char> spellV;

bool check(string str)
{
    set<char> st;
    map<char, int> mp;
    for (int i = 0; i < str.size(); i++)
    {
        st.insert(str[i]);
    }

    for (char ch : st)
    {
        for (int i = 0; i < spellV.size(); i++)
        {
            if (ch == spellV[i])
            {
                mp[ch]++;
            }
        }
    }

    if (mp.size() != spellV.size())
    {
        return false;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second != 1)
        {
            return false;
        }
    }
    return true;
}
int solution(vector<string> spell, vector<string> dic)
{
    int answer = 0;
    for (string str : spell)
    {
        spellV.push_back(str[0]);
    }
    for (int i = 0; i < dic.size(); i++)
    {
        if (check(dic[i]))
        {
            answer = 1;
            return answer;
        }
        else
        {
            answer = 2;
        }
    }
    return answer;
}