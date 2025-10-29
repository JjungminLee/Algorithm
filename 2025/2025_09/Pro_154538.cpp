#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;

int solution(int x, int y, int n)
{
    int answer = 0;
    q.push({x, 0});
    if (x == y)
        return 0;
    bool visited[10000000] = {
        false,
    };

    while (!q.empty())
    {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (num > y)
        {
            continue;
        }
        if (num == y)
        {
            return cnt;
        }
        int calculate[3] = {num + n, num * 2, num * 3};
        for (int i = 0; i < 3; i++)
        {
            if (!visited[calculate[i]])
            {
                visited[calculate[i]] = true;
                q.push({calculate[i], cnt + 1});
            }
        }
    }
    return -1;
}