#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++)
    {
        vector<string> tmp = clothes[i];
        mp[tmp[1]]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        answer *= (it->second + 1);
    }
    return answer - 1;
}