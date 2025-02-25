#include <bits/stdc++.h>
using namespace std;
int n, l, r;
long long dp[101][101][101];
int MOD = 1000000007;
int main()
{
    cin >> n >> l >> r;
    dp[1][1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 1; k <= i; k++)
            {

                dp[i][j][k] = (dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2)) % MOD;
            }
        }
    }
    cout << dp[n][l][r] << endl;
}