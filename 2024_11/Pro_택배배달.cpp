#include <bits/stdc++.h>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int d = n - 1, p = n - 1;

    while (d >= 0 || p >= 0)
    {
        int capacity = cap;
        int maxDistance = 0;
        // 0이면 건너뛴다.
        while (d >= 0 && deliveries[d] == 0)
        {
            d--;
        }
        if (d >= 0)
        {
            // 왕복거리는 p와 d중 먼곳을 기준으로 하기 때문
            maxDistance = max(maxDistance, d + 1);
        }
        while (d >= 0 && capacity > 0)
        {
            if (deliveries[d] <= capacity)
            {
                capacity -= deliveries[d];
                deliveries[d] = 0;
                d--;
            }
            else
            {
                deliveries[d] -= capacity;
                capacity = 0;
            }
        }
        capacity = cap;
        while (p >= 0 && pickups[p] == 0)
        {
            p--;
        }
        if (p >= 0)
        {
            maxDistance = max(maxDistance, p + 1);
        }

        while (capacity > 0 && p >= 0)
        {
            if (pickups[p] <= capacity)
            {
                capacity -= pickups[p];
                p--;
                // 0으로 바꿔줘야
                pickups[p] = 0;
            }
            else
            {
                pickups[p] -= capacity;
                capacity = 0;
            }
        }
        answer += 2 * (maxDistance);
    }

    return answer;
}

int main()
{
    vector<int> deliveries = {1, 0, 3, 1, 2};
    vector<int> pickups = {0, 3, 0, 4, 0};
    int ans = solution(4, 5, deliveries, pickups);
    cout << ans << endl; // 16이 출력되어야 합니다.

    vector<int> deliveries2 = {1, 0, 2, 0, 1, 0, 2};
    vector<int> pickups2 = {0, 2, 0, 1, 0, 2, 0};
    int ans2 = solution(2, 7, deliveries2, pickups2);
    cout << ans2 << endl; // 30이 출력되어야 합니다.
}
