#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[101];
int main()
{
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= 100; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2];
    }
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        cout << dp[k] << '\n';
    }
}