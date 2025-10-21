#include <bits/stdc++.h>

using namespace std;

// {화살 던진 전체 횟수, 싱글 또는 볼을 던진 횟수 }
vector<pair<int, int>> dp(100000, {INT_MAX, 0});

bool findBetter(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

// 최소한의 다트로 0을 만든다
// 싱글 또는 볼을 최대한 많이 던진다
vector<int> solution(int target)
{
    vector<int> answer;
    dp[0] = {0, 0};
    for (int i = 1; i <= target; i++)
    {
        dp[i] = {INT_MAX, -1};
    }
    for (int i = 0; i <= target; i++)
    {
        if (dp[i].first == INT_MAX)
            continue;

        // 싱글
        for (int s = 1; s <= 20; s++)
        {
            if (i + s <= target)
            {
                pair<int, int> newState = {dp[i].first + 1, dp[i].second + 1};
                if (findBetter(newState, dp[i + s]))
                {
                    dp[i + s] = newState;
                }
            }
        }

        // 더블
        for (int s = 1; s <= 20; s++)
        {
            int num = s * 2;
            if (i + num <= target)
            {
                pair<int, int> newState = {dp[i].first + 1, dp[i].second};
                if (findBetter(newState, dp[i + num]))
                {
                    dp[i + num] = newState;
                }
            }
        }

        // 트리플
        for (int s = 1; s <= 20; s++)
        {
            int num = s * 3;
            if (i + num <= target)
            {
                pair<int, int> newState = {dp[i].first + 1, dp[i].second};
                if (findBetter(newState, dp[i + num]))
                {
                    dp[i + num] = newState;
                }
            }
        }

        // 50
        if (i + 50 <= target)
        {
            pair<int, int> newState = {dp[i].first + 1, dp[i].second + 1};
            if (findBetter(newState, dp[i + 50]))
            {
                dp[i + 50] = newState;
            }
        }
    }

    return {dp[target].first, dp[target].second};
}