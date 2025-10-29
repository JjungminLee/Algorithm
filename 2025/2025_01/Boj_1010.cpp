#include <bits/stdc++.h>
using namespace std;
int t;
int ans;
int combination(int n, int r)
{
    int res = 1;
    if (r > n - r)
    {
        r = n - r;
    }
    for (int i = 0; i < r; i++)
    {
        res = (res * (n - i)) / (i + 1);
    }
    return res;
}
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        int ans = combination(b, a);
        cout << ans << endl;
    }
}