#include <bits/stdc++.h>

using namespace std;
set<string> st;
int startPoint = 0;
int endPoint = 0;
int minNum = INT_MAX;

map<string, int> mp;
vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    int n = 0;

    for (string str : gems)
    {
        st.insert(str);
    }

    n = st.size();

    int left = 0;
    int right = 0;
    while (left <= right && right < gems.size())
    {
        mp[gems[right]]++;
        while (mp.size() == n)
        {
            if (right - left < minNum)
            {
                startPoint = left;
                endPoint = right;
                minNum = right - left;
            }
            mp[gems[left]]--;
            if (mp[gems[left]] == 0)
            {
                mp.erase(gems[left]);
            }
            // 좁히기
            left++;
        }
        right++;
    }

    answer.push_back(startPoint + 1);
    answer.push_back(endPoint + 1);
    return answer;
}