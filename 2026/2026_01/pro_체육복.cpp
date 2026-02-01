#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                // 지우면서 인덱스 앞으로 당겨오니가
                i--;
                break;
            }
        }
    }
    answer = (n - lost.size());
    for (int i = 0; i < lost.size(); i++)
    {
        bool flag = false;
        int rIdx = 0;
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j])
            {
                flag = true;
                rIdx = j;
                break;
            }
        }
        if (flag)
        {
            answer++;
            reserve.erase(reserve.begin() + rIdx);
        }
    }

    return answer;
}