#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dp[302][302];
vector<pair<int, int>> v[302];
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    memset(dp, -1, sizeof(dp));
    dp[1][1] = 0;
    // dp[i][j] -> i는 방문한 도시 개수 j는 현재 위치한 도시

    queue<pair<int, int>> q;
    q.push({1, 1});

    while (!q.empty())
    {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt > m)
        {
            continue;
        }
        for (int i = 0; i < v[num].size(); i++)
        {
            int b = v[num][i].first;
            int c = v[num][i].second;

            if (dp[cnt][num] != -1 && num < b)
            {
                if (cnt + 1 > m)
                {
                    continue;
                }
                if (dp[cnt + 1][b] < dp[cnt][num] + c)
                {
                    dp[cnt + 1][b] = max(dp[cnt + 1][b], dp[cnt][num] + c);
                    q.push({b, cnt + 1});
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {

        ans = max(ans, dp[i][n]);
    }
    cout << ans << endl;
}