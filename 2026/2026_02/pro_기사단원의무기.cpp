#include <bits/stdc++.h>

using namespace std;

int arr[100005];
int solution(int number, int limit, int power)
{
    int answer = 0;
    for (int i = 1; i <= number; i++)
    {
        int cnt = 0;
        for (int k = 1; k * k <= i; k++)
        {
            if (i % k == 0)
            {
                cnt++;
                if (k * k != i)
                {
                    cnt++;
                }
            }
        }
        arr[i] = cnt;
    }
    for (int i = 1; i <= number; i++)
    {
        if (arr[i] <= limit)
        {
            answer += arr[i];
        }
        else
        {
            answer += power;
        }
    }
    return answer;
}