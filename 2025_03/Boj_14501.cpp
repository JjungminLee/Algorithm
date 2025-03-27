#include <bits/stdc++.h>
using namespace std;
int n;
int t[16];
int p[16];
int dp[16];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        cin >> p[i];
    }
    for (int i = 1; i <= n + 1; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]); // 값 유지
        for (int j = 1; j < i; j++)
        {
            if (j + t[j] == i)
            {
                dp[i] = max(dp[i], dp[j] + p[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }
    cout << ans << endl;
}