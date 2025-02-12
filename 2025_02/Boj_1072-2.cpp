#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y;
int main()
{
    cin >> x >> y;
    ll z = (y * 100) / x;
    if (z >= 99)
    {
        cout << -1 << endl;
        return 0;
    }
    ll left = 0;
    ll right = 1e9;
    int ans = -1;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll newz = ((y + mid) * 100) / (x + mid);
        if (newz > z)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << left << endl;
}