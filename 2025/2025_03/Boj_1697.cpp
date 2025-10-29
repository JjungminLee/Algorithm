#include <bits/stdc++.h>
using namespace std;
int n, k;
int visited[100001];
int main()
{
    cin >> n >> k;
    visited[n] = true;
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty())
    {

        int num = q.front().first;
        int cnt = q.front().second;

        q.pop();
        if (num == k)
        {
            cout << cnt << endl;
            return 0;
        }
        if (num - 1 >= 0 && !visited[num - 1])
        {
            visited[num - 1] = true;
            q.push({num - 1, cnt + 1});
        }
        if (num + 1 <= 100000 && !visited[num + 1])
        {
            visited[num + 1] = true;
            q.push({num + 1, cnt + 1});
        }
        if (2 * num <= 100000 && !visited[2 * num])
        {
            visited[2 * num] = true;
            q.push({2 * num, cnt + 1});
        }
    }
}