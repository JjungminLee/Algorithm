#include <bits/stdc++.h>
using namespace std;
int n;
char arr[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist[50][50];
void dijkstra()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;
    while (!pq.empty())
    {
        int cnt = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        if (x == n - 1 && y == n - 1)
        {
            cout << cnt << endl;
            return;
        }

        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                int newCnt = cnt;
                if (arr[nx][ny] == '0')
                {
                    newCnt++;
                }
                if (newCnt < dist[nx][ny])
                {
                    dist[nx][ny] = newCnt;
                    pq.push({newCnt, {nx, ny}});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j];
            dist[i][j] = INT_MAX;
        }
    }

    dijkstra();
}