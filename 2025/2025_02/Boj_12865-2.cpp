#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[100001];
int w[100001];
int v[100001];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[k] << endl;
}