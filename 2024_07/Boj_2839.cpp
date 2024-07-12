#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int main()
{
    cin >> n;
    while (n >= 0)
    {
        if (n % 5 == 0)
        {
            ans += (n / 5);
            cout << ans << endl;
            return 0;
        }
        n -= 3;
        ans++;
    }
    cout << -1 << endl;
}