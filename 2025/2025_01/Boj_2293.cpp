#include <bits/stdc++.h>
using namespace std;
int n, k;
long long dp[10001];
int arr[101];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int coin = arr[i];
        for (int j = coin; j <= k; j++)
        {
            dp[j] += dp[j - coin];
        }
    }
    cout << dp[k] << endl;
}