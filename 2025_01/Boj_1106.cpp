#include <bits/stdc++.h>
using namespace std;
int c, n;
const int I = 2001;
long long dp[I];
int main()
{
    cin >> c >> n;
    for (int i = 1; i <= I - 1; i++)
    {
        dp[i] = INT_MAX;
    }

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        dp[b] = min(dp[b], (long long)a);
    }

    // dp[고객 c]=가격

    for (int i = 2; i <= I - 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
    }

    int ans = INT_MAX;

    for (int i = c; i <= I - 1; i++)
    {
        if (ans > dp[i])
        {
            ans = dp[i];
        }
    }
    cout << ans << endl;
}