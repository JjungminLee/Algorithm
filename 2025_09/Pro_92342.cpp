#include <bits/stdc++.h>
using namespace std;

vector<int> maxV(11);
int maxDiff;
bool flag = false;
void backTracking(int cur, vector<int> apeachs, vector<int> ryans, int n)
{
    if (cur == 11)
    {
        if (n > 0)
        {
            ryans[10] += n;
        }
        int apeach = 0;
        int ryan = 0;
        for (int i = 0; i < 11; i++)
        {
            if (apeachs[i] == 0 && ryans[i] == 0)
                continue;
            if (apeachs[i] >= ryans[i])
            {
                apeach += (10 - i);
            }
            else
            {
                ryan += (10 - i);
            }
        }

        int curDiff = ryan - apeach;
        if (maxDiff < curDiff)
        {
            flag = true;
            maxDiff = curDiff;
            maxV = ryans;
        }
        else if (maxDiff == curDiff)
        {
            for (int i = 10; i >= 0; i--)
            {
                if (ryans[i] > maxV[i])
                {
                    maxV = ryans;
                    break;
                }
                else if (ryans[i] < maxV[i])
                {
                    break;
                }
            }
        }

        return;
    }
    if (n > apeachs[cur])
    {
        ryans[cur] = apeachs[cur] + 1;
        backTracking(cur + 1, apeachs, ryans, n - (apeachs[cur] + 1));
        ryans[cur] = 0;
    }
    backTracking(cur + 1, apeachs, ryans, n);
}
vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    vector<int> tmp(11, 0);
    backTracking(0, info, tmp, n);
    if (!flag)
    {
        answer.push_back(-1);
        return answer;
    }
    return maxV;
}