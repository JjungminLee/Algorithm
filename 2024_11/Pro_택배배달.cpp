#include <bits/stdc++.h>
using namespace std;
/*

- 잘한것
-> 가장 idx가 큰걸 기준으로 ans에 더해야하는거

- 못한것
문제를 잘못 이해 -> 0이 아닌 경우에 대해서 최대한 멀리서부터 탐색 x, cap보다 작으면 못빼는게 아님, deliveries[i]만큼 전부 소거가 아닌점
 */

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int d = n - 1;
    int p = n - 1;

    while (d >= 0 || p >= 0)
    {
        int capacity = cap;
        int maxDistance = 0;
        // 더이상 배달할것들이 없는 경우
        if (d >= 0 && deliveries[d] == 0)
        {
            d--;
        }
        if (d >= 0)
        {
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

        while (p >= 0 && pickups[p] == 0)
        {
            p--;
        }
        while (p >= 0 && capacity > 0)
        {
            if (pickups[p] <= capacity)
            {

                capacity -= pickups[p];
                pickups[p] = 0;
                p--;
            }
            else
            {
                pickups[p] -= capacity;
                capacity = 0;
            }
        }
        answer += (maxDistance) * 2;
    }

    return answer;
}

int main()
{
    vector<int> deliveries = {1, 0, 3, 1, 2};
    vector<int> pickups = {0, 3, 0, 4, 0};
    int ans = solution(4, 5, deliveries, pickups);
    cout << ans << endl; // 16
    vector<int> deliveries2 = {1, 0, 2, 0, 1, 0, 2};
    vector<int> pickups2 = {0, 2, 0, 1, 0, 2, 0};
    int ans2 = solution(2, 7, deliveries2, pickups2);
    cout << ans2 << endl; // 30
}
