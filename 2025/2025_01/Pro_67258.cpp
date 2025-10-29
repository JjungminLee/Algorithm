#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;

    unordered_set<string> uset;
    unordered_map<string, int> visited;
    for (int i = 0; i < gems.size(); i++)
    {
        uset.insert(gems[i]);
    }
    int typeCnt = uset.size();
    int start = 0;
    int end = 0;
    int minLen = INT_MAX;
    int left = 0;
    int right = 0;
    int cnt = 0;

    while (right < gems.size())
    {

        if (visited[gems[right]] == 0)
        {
            cnt++;
        }
        visited[gems[right]]++;
        right++;
        // 가장 최소 구간 찾기
        while (typeCnt == cnt)
        {
            if (right - left < minLen)
            {
                start = left;
                end = right;
                minLen = right - left;
            }
            visited[gems[left]]--;
            if (visited[gems[left]] == 0)
            {
                cnt--;
            }
            left++;
        }
    }
    answer.push_back(start + 1);
    answer.push_back(end);

    return answer;
}