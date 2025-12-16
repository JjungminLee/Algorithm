#include <bits/stdc++.h>

using namespace std;
int n;

int solution(vector<int> a)
{
    int answer = 0;
    n = a.size();
    vector<int> left(n);
    vector<int> right(n);

    int minNum = a[0];
    for (int i = 0; i < n; i++)
    {
        if (minNum > a[i])
        {
            minNum = a[i];
        }
        left[i] = minNum;
    }
    minNum = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (minNum > a[i])
        {
            minNum = a[i];
        }
        right[i] = minNum;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= left[i] || a[i] <= right[i])
        {
            answer++;
        }
    }

    return answer;
}