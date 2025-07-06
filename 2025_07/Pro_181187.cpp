#include <bits/stdc++.h>

using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;
    long long r1Squared = 1LL * r1 * r1;
    long long r2Squared = 1LL * r2 * r2;
    for (int x = 0; x <= r2; x++)
    {
        long long xSquared = 1LL * x * x;
        long long maxY = (long long)floor(sqrt(r2Squared - xSquared));
        long long minY = 0;
        if (r1Squared > xSquared)
        {
            minY = (long long)ceil(sqrt(r1Squared - xSquared));
        }
        else
        {
            minY = 0;
        }

        long long cnt = maxY - minY + 1;
        if (cnt <= 0)
        {
            continue;
        }

        if (x == 0)
        {
            answer += 2 * cnt;
        }
        else if (minY > 0)
        {
            answer += 4 * cnt;
        }
        else
        {
            answer += 2 + 4 * (cnt - 1);
        }
    }

    return answer;
}