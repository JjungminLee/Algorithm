#include <bits/stdc++.h>

using namespace std;

int maxDiff = 0;
vector<int> maxV(11);
void backtracking(int idx, int n, vector<int> info, vector<int> v)
{
    // 0점부터 10점까지 다 쐈는가?
    if (idx == 11)
    {
        if (n > 0)
        {
            // 화살 다 쓰기
            v[10] += n;
        }
        int apeach = 0;
        int ryan = 0;
        for (int i = 0; i < 11; i++)
        {
            if (v[i] == 0 && info[i] == 0)
            {
                continue;
            }
            if (v[i] > info[i])
            {
                ryan += (10 - i);
            }
            else if (v[i] <= info[i])
            {
                apeach += (10 - i);
            }
        }
        if (ryan > apeach)
        {
            int diff = ryan - apeach;
            if (diff > maxDiff)
            {
                maxDiff = diff;
                maxV = v;
            }
            else if (diff == maxDiff)
            {
                for (int i = 10; i >= 0; i--)
                {
                    if (v[i] > maxV[i])
                    {
                        maxV = v;
                        break;
                    }
                    else if (v[i] < maxV[i])
                    {
                        break;
                    }
                }
            }
        }
        return;
    }
    // 라이언이 어피치 보다 1점 더 크게 맞추거나 아예 안맞추거나 해야 가장 최적의 값이 나옴!
    if (n >= info[idx] + 1)
    {
        v[idx] = info[idx] + 1;
        backtracking(idx + 1, n - (info[idx] + 1), info, v);
        v[idx] = 0;
    }
    backtracking(idx + 1, n, info, v);
}
vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    vector<int> v(11);
    backtracking(0, n, info, v);
    int cnt = 0;
    for (int i = 0; i < maxV.size(); i++)
    {
        cnt += maxV[i];
    }
    if (cnt == 0)
    {
        answer.push_back(-1);
    }
    else
    {
        answer = maxV;
    }
    return answer;
}