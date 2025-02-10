#include <bits/stdc++.h>
using namespace std;
long long x, y;

int main()
{
    cin >> x >> y;
    long long z = y * 100 / x;
    if (z >= 99)
    {
        cout << -1 << endl;
        return 0;
    }
    long long left = 0;
    long long right = 1000000000;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long newz = (y + mid) * 100 / (x + mid);
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