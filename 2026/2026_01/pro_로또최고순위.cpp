#include <bits/stdc++.h>

using namespace std;
map<int, int> mp;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int minNum = 0;
    int maxNum = 0;
    mp[6] = 1;
    mp[5] = 2;
    mp[4] = 3;
    mp[3] = 4;
    mp[2] = 5;
    mp[1] = 6;
    mp[0] = 6;

    for (int i = 0; i < 6; i++)
    {
        if (lottos[i] == 0)
        {
            maxNum++;
        }
        for (int j = 0; j < 6; j++)
        {
            if (lottos[i] == win_nums[j])
            {
                maxNum++;
                minNum++;
                break;
            }
        }
    }
    answer.push_back(mp[maxNum]);
    answer.push_back(mp[minNum]);
    return answer;
}