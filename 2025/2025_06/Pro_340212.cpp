#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
int solution(vector<int> diffs, vector<int> times, long long limit)
{
    int answer = 0;
    int minDiff = INT_MAX;
    int maxDiff = 0;
    for (int i = 0; i < diffs.size(); i++)
    {
        v.push_back({diffs[i], times[i]});
        minDiff = min(minDiff, diffs[i]);
        maxDiff = max(maxDiff, diffs[i]);
    }
    // 순서대로 퍼즐을 풀어야하므로 정렬은 안씀
    int left = minDiff;
    int right = maxDiff;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first <= mid)
            {
                cnt += v[i].second;
            }
            else
            {
                // time_prev가 없는 경우 time_cur이 제일 첫번째인경우?
                cnt += (v[i].first - mid) * (v[i].second + v[i - 1].second) + v[i].second;
            }
        }
        // 기존 이진탐색이랑 로직이 다름
        // level을 높여서 소요시간을 줄이기
        if (cnt <= limit)
        {                    // cnt>limit일때가 아님! cnt<=limit이면 level을 더 줄일수 있는지 확인 -> 최소 level 찾는거기 때문
            right = mid - 1; //  right--이 아니라 right=mid-1임!
            answer = mid;
        }
        else
        { // 소요시간을 줄이기 위해 level을 키우기
            left = mid + 1;
        }
    }
    return left;
}