#include <bits/stdc++.h>
using namespace std;
int n;
int ans = 0;
const int num = 1000001;
long long dp[num];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            dp[j] += i;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i] += dp[i - 1];
    }
    cout << dp[n] << endl;
}