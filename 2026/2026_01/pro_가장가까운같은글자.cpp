#include <bits/stdc++.h>

using namespace std;
// 처음 지점 끝지점
map<char, vector<int>> mp;
vector<int> solution(string s)
{
    vector<int> answer;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (mp[ch].size() == 0)
        {
            answer.push_back(-1);
            mp[ch] = {0, i};
        }
        else
        {
            int startP = mp[ch][1];
            int endP = i;
            int newVal = endP - startP;
            mp[ch] = {endP, i};
            answer.push_back(newVal);
        }
    }
    return answer;
}