#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int gender[1001];
int parents[1001];
int ans;

int find(int a)
{
    if (a == parents[a])
    {
        return a;
    }
    return parents[a] = find(parents[a]);
}
bool isCycle(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x == y)
    {
        return true;
    }
    return false;
}

void unions(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x < y)
    {
        parents[y] = x;
    }
    else
    {
        parents[x] = y;
    }
}
int main()
{
    vector<tuple<int, int, int>> v;
    cin >> n >> m;
    for (int i = 0; i < 1001; i++)
    {
        parents[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == 'M')
        {
            gender[i] = 1;
        }
        else
        {
            gender[i] = 2;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int start, end, dist;
        cin >> start >> end >> dist;
        start -= 1;
        end -= 1;
        v.push_back({dist, start, end});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        int start, end, dist;
        tie(dist, start, end) = v[i];
        if (gender[start] != gender[end])
        {
            if (!isCycle(start, end))
            {
                unions(start, end);
                ans += dist;
            }
        }
    }
    bool flag = false;
    int std = find(parents[0]);
    for (int i = 1; i < n; i++)
    {
        if (find(parents[i]) != std)
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}