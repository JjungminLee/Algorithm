#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int arr[101][101];
int ans[101];

void bfs(int num)
{

    bool visits[101] = {
        0,
    };
    int tot = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        if (i == num)
        {
            continue;
        }
        if (arr[num][i] != 0 && !visits[i])
        {

            q.push({i, 1});
            tot++;
            visits[i] = true;
        }
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for (int i = 0; i < n; i++)
        {

            if (arr[x][i] != 0 && !visits[i] && i != num)
            {

                y += 1;
                q.push({i, y + 1});
                tot += y;
                visits[i] = true;
            }
        }
    }

    ans[num] = tot;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a - 1][b - 1] = 1;
        arr[b - 1][a - 1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        bfs(i);
    }
    int min = INT_MAX;
    int ansIdx = 0;
    for (int i = 0; i < n; i++)
    {
        if (min > ans[i])
        {
            ansIdx = i;
            min = ans[i];
        }
    }
    cout << ansIdx + 1 << endl;
}