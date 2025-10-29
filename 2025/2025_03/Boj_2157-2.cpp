#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>> v[301];
int dp[301][301]; // dp[도시 몇개 갔는지][현재 도시]
int main()
{
    cin >> n >> m >> k;
    queue<pair<int, int>> q;
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    q.push({1, 1});
    memset(dp, -1, sizeof(dp));

    dp[1][1] = 0; // 중요
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
            if (num < b && dp[cnt + 1][b] < dp[cnt][num] + c)
            {
                dp[cnt + 1][b] = max(dp[cnt + 1][b], dp[cnt][num] + c);

                q.push({b, cnt + 1});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        ans = max(ans, dp[i][n]);
    }
    cout << ans << endl;
}