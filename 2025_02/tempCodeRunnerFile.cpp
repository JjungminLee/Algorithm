#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[100001];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        dp[a] = b;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= i; j++)
        {

            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }
    cout << dp[k] << endl;
}