#include <bits/stdc++.h>

using namespace std;
long long arr1[500001];
long long arr2[500001];

long long solution(vector<int> sequence)
{
    long long answer = 0;
    for (int i = 0; i < sequence.size(); i++)
    {
        if (i % 2 == 0)
        {
            arr1[i] = sequence[i];
        }
        else
        {
            arr1[i] = sequence[i] * (-1);
        }
    }
    for (int i = 0; i < sequence.size(); i++)
    {
        if (i % 2 == 0)
        {
            arr2[i] = sequence[i] * (-1);
        }
        else
        {
            arr2[i] = sequence[i];
        }
    }
    long long sum1 = 0;
    long long cur1 = 0;
    long long sum2 = 0;
    long long cur2 = 0;
    for (int i = 0; i < sequence.size(); i++)
    {
        cur1 = max(arr1[i], cur1 + arr1[i]);
        sum1 = max(sum1, cur1);
    }
    for (int i = 0; i < sequence.size(); i++)
    {
        cur2 = max(arr2[i], cur2 + arr2[i]);
        sum2 = max(sum2, cur2);
    }
    answer = max(sum1, sum2);
    return answer;
}