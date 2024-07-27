#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100010];
int dp[100010];
int ans = INT_MIN;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)

    {
        dp[i] = arr[i];
    }

    // dp로 구해야함
    for (int i = 0; i < n; i++)
    {
        // 이번껄 포함하기,기존꺼, 이번꺼 포함안하고 지나가기
        dp[i] = max(dp[i - 1] + arr[i], dp[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (ans < dp[i])
        {
            ans = dp[i];
        }
    }
    cout << ans << endl;
}