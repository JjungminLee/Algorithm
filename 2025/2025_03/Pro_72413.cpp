#include <bits/stdc++.h>

using namespace std;
int dist[201][201];
int maxINT = 2000000;
int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dist[i][j] = maxINT;
        }
    }
    for (int i = 0; i < fares.size(); i++)
    {
        int c = fares[i][0];
        int d = fares[i][1];
        int f = fares[i][2];

        dist[c][d] = min(dist[c][d], f);
        dist[d][c] = min(dist[d][c], f);
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int ans = maxINT;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    return ans;
}