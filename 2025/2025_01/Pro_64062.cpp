#include <bits/stdc++.h>

using namespace std;

int check(int mid, vector<int> stones, int k)
{
    int skip = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - mid < 0)
        {
            skip++;
            if (skip >= k)
            {
                return 0;
            }
        }
        else
        {
            skip = 0;
        }
    }
    return 1;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    // 최대 몇명이 징검다리를 건너느냐가 중요 [1명,max(stones)]
    int left = 1;

    int maxStone = INT_MIN;
    for (int i = 0; i < stones.size(); i++)
    {
        if (maxStone < stones[i])
        {
            maxStone = stones[i];
        }
    }
    int right = maxStone;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid, stones, k) == 1)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return answer;
}