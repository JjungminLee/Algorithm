#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long ans = LLONG_MAX;

long long bfs(int num)
{
    queue<pair<long long, long long>> q;
    q.push({num, 0});
    while (!q.empty())
    {
        long long x = q.front().first;
        long long count = q.front().second;

        q.pop();

        if (b == x)
        {
            ans = min(count, ans);

            return ans + 1;
        }
        else
        {
            if (x * 2 <= b)
            {
                q.push({x * 2, count + 1});
            }
            if (x * 10 + 1 <= b)
            {
                q.push({x * 10 + 1, count + 1});
            }
        }
    }
    return -1;
}
int main()
{
    cin >> a >> b;
    cout << bfs(a) << endl;
}