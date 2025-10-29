#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int result = 0;

int solution(int n, vector<int> weak, vector<int> dist)
{

    int len = weak.size();
    int answer = dist.size() + 1;
    // 원형을 선형으로
    for (int i = 0; i < len; i++)
    {
        weak.push_back(weak[i] + n);
    }
    sort(dist.begin(), dist.end());

    do
    {
        for (int start = 0; start < len; start++)
        {
            int friend_idx = 0;
            int position = weak[start] + dist[friend_idx];

            int i;
            for (i = start; i < start + len; i++)
            {
                if (weak[i] > position)
                {
                    friend_idx++;
                    if (friend_idx >= dist.size())
                        break;
                    position = weak[i] + dist[friend_idx];
                }
            }

            if (i == start + len)
            {
                answer = min(answer, friend_idx + 1);
            }
        }

    } while (next_permutation(dist.begin(), dist.end()));
    if (answer > dist.size())
        return -1;
    return answer;
}