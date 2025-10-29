#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool visited[100001];
int dp[100001][2];

void dfs(int cur, int prev)
{
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for (int next : adj[cur])
    {
        if (next == prev)
            continue;
        if (visited[next])
            continue;
        dfs(next, cur);
        // 자식값 먼저 계산후 부모로 누적
        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }
}
int solution(int n, vector<vector<int>> lighthouse)
{
    int answer = 0;

    for (int i = 0; i < lighthouse.size(); i++)
    {
        int parent = lighthouse[i][0];
        int child = lighthouse[i][1];
        adj[parent].push_back(child);
        adj[child].push_back(parent);
    }
    dfs(1, 0);

    return min(dp[1][0], dp[1][1]);
}