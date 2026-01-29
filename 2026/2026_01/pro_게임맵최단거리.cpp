#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[105][105];
struct Node
{
    int x;
    int y;
    int cnt;
};

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();

    int answer = 0;
    queue<Node> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int cnt = cur.cnt;
        if (x == n - 1 && y == m - 1)
        {
            answer = cnt;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && maps[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, cnt + 1});
                }
            }
        }
    }
    if (answer == 0)
    {
        return -1;
    }

    return answer;
}