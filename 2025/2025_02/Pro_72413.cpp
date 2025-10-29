#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000;
int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < fares.size(); i++)
    {
        int a = fares[i][0];
        int b = fares[i][1];
        int d = fares[i][2];
        dist[a][b] = min(dist[a][b], d);
        dist[b][a] = min(dist[b][a], d);
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
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int answer = INF;
    for (int i = 1; i <= n; i++)
    {

        answer = min(dist[s][i] + dist[i][a] + dist[i][b], answer);
    }
    return answer;
}