#include <bits/stdc++.h>
using namespace std;
int n;
int ans = INT_MAX;
int arr[1001][3];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int first = 0; first < 3; first++)
    {
        int dp[1001][3] = {
            0,
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = 1e9;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (i == first)
            {
                dp[0][i] = arr[0][i];
            }
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
        }

        for (int i = 0; i < 3; i++)
        {
            if (i != first)
            {
                ans = min(dp[n - 1][i], ans);
            }
        }
    }
    cout << ans << endl;
}