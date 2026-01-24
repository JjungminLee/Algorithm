#include <bits/stdc++.h>

using namespace std;
map<string, int> mp;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    for (string s : participant)
    {
        mp[s] += 1;
    }

    for (string c : completion)
    {
        auto it = mp.find(c);
        if (it != mp.end())
        {
            mp[it->first] -= 1;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > 0)
        {
            answer = it->first;
        }
    }
    return answer;
}