#include <bits/stdc++.h>

using namespace std;

// 원의 방정식으로 풀어야!
long long solution(int k, int d)
{
    long long answer = 0;

    for (long long x = 0; x <= d; x += k)
    {
        long long y = sqrt(1LL * d * d - 1LL * x * x);
        answer += y / k + 1;
    }
    return answer;
}