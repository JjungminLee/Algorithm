#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> emergency)
{
    vector<int> answer;
    vector<int> sv;
    for (int i = 0; i < emergency.size(); i++)
    {
        sv.push_back(emergency[i]);
    }
    sort(sv.begin(), sv.end(), greater<>());

    for (int i = 0; i < emergency.size(); i++)
    {
        for (int j = 0; j < sv.size(); j++)
        {
            if (emergency[i] == sv[j])
            {
                answer.push_back(j + 1);
                break;
            }
        }
    }
    return answer;
}