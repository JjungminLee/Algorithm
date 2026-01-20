#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<int> v;
    int same = 0;
    int different = 0;
    int idx = 0;

    while (idx < s.size())
    {
        // cout<<"idx "<<idx<<endl;
        char cur = s[idx];
        same = 1;
        different = 0;

        for (int i = idx + 1; i < s.size(); i++)
        {
            if (s[i] != cur)
            {
                different++;
            }
            else
            {
                same++;
            }

            if (same == different)
            {
                v.push_back(i + 1);
                idx = i + 1;
                break;
            }
        }

        if (same != different)
        {
            v.push_back(idx);
            break; // while문 자체를 탈출
        }
    }
    answer = v.size();
    return answer;
}