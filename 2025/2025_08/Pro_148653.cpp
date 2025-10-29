#include <bits/stdc++.h>
using namespace std;

int solution(int storey)
{
    string str = to_string(storey);
    vector<int> v;
    int answer = 0;
    for (int i = 0; i < str.size(); i++)
    {
        v.push_back(str[i] - '0');
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] == 5)
        {
            if (i == 0)
            {
                answer += 5;
                continue;
            }
            if (i - 1 >= 0 && v[i - 1] < 5)
            {
                answer += v[i];
            }
            else
            {
                answer += (10 - v[i]);
                int idx = i - 1;
                while (idx >= 0 && v[idx] == 9)
                {
                    v[idx] = 0;
                    idx--;
                }
                if (idx < 0)
                {
                    answer += 1;
                }
                else
                {
                    v[idx] += 1;
                }
            }
        }
        else if (v[i] < 5)
        {
            answer += v[i];
        }
        else if (v[i] > 5)
        {
            answer += (10 - v[i]);
            int idx = i - 1;
            while (idx >= 0 && v[idx] == 9)
            {
                v[idx] = 0;
                idx--;
            }
            if (idx < 0)
            {
                answer += 1;
            }
            else
            {
                v[idx] += 1;
            }
        }
    }

    return answer;
}