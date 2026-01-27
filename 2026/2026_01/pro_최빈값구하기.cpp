#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array)
{
    int answer = 0;
    map<int, int> mp;
    for (int num : array)
    {
        mp[num]++;
    }

    int maxNum = 0;
    int maxCnt = INT_MIN;
    int dupl = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (maxCnt < it->second)
        {
            maxNum = it->first;
            maxCnt = it->second;
            dupl = 0;
        }
        else if (maxCnt == it->second)
        {
            dupl++;
        }
    }

    if (dupl > 0)
    {
        return -1;
    }
    return maxNum;
}