#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;

int solution(vector<int> nums)
{
    int answer = 0;
    int allow = nums.size() / 2;
    for (int num : nums)
    {
        mp[num]++;
    }

    if (allow > mp.size())
    {
        answer = mp.size();
    }
    else
    {
        answer = allow;
    }
    return answer;
}