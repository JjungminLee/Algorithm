#include <bits/stdc++.h>
using namespace std;
int x, y;

typedef long long ll;
bool check(ll mid)
{
    return x * (y + mid) > y * (x + mid);
}
int main()
{
    cin >> x >> y;
    ll z = (y * 100) / x;
    if (z >= 99)
    {
        cout << -1 << endl;
        return 0;
    }
    ll left = 1;
    ll right = 1e9;
    int ans = -1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;

        if (check(mid))
        { // 승률이 변했으면 더 최소값을 탐색
            ans = mid;
            // 최소값 탐색
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans << endl;
}