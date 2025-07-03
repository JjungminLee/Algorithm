#include <bits/stdc++.h>
using namespace std;

long long n, m, k;
long long dp[101][101];

int main()
{
    cin >> n >> m >> k;
    // 한쪽이 0인거는 다 1이되게 초기화 중요!
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            if (dp[i][j] > 1e9)
            {
                dp[i][j] = 1e9;
            }
        }
    }

    long long size = dp[n][m];

    if (size < k)
    {
        cout << -1 << endl;
    }
    else
    {
        string res = "";
        while (n > 0 || m > 0)
        {
            if (n == 0)
            {
                res += 'z';
                m--;
            }
            else if (m == 0)
            {
                res += 'a';
                n--;
            }
            else
            {
                // a부터 쳐내기
                long long cnt = dp[n - 1][m];
                if (k <= cnt)
                { // k번째 문자열이 a로 시작하는 문자열 일때
                    res += 'a';
                    n--;
                }
                else
                {
                    res += 'z';
                    k -= cnt;
                    m--;
                }
            }
        }
        cout << res << endl;
    }
}