#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    // 던전을 어떤 순서로 방문할건지 ? -> 순열로
    vector<int> per;
    for (int i = 0; i < dungeons.size(); i++)
    {
        per.push_back(i);
    }

    do
    {
        int currK = k;
        int res = 0;
        for (int i = 0; i < per.size(); i++)
        {

            vector<int> vv = dungeons[per[i]];
            int minimum = vv[0];
            int usages = vv[1];

            if (currK >= minimum)
            {
                currK -= usages;
                res++;
            }
        }
        answer = max(answer, res);

    } while (next_permutation(per.begin(), per.end()));
    return answer;
}