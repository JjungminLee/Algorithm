#include <bits/stdc++.h>

using namespace std;
map<string, int> mp;

bool isCorrect(map<string, int> submap)
{
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        string str = it->first;
        int num = it->second;
        if (submap[str] != num)
        {
            return false;
        }
    }
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    for (int i = 0; i < want.size(); i++)
    {
        string wants = want[i];
        int numbers = number[i];
        mp[wants] = numbers;
    }
    for (int i = 0; i < discount.size(); i++)
    {
        int start = i;
        map<string, int> submap;
        for (int j = start; j < start + 10 && j < discount.size(); j++)
        {
            string str = discount[j];
            submap[str]++;
        }
        if (isCorrect(submap))
        {
            answer++;
        }
    }
    return answer;
}