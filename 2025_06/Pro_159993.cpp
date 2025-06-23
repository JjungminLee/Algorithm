#include <bits/stdc++.h>

using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char arr[101][101];
bool visited[101][101];
int n;
int m;
int sx;
int sy;
int lx;
int ly;

struct Node
{
    int x;
    int y;
    int times;
};
int laverBfs()
{
    queue<Node> q;
    visited[sx][sy] = true;
    q.push({sx, sy, 0});
    while (!q.empty())
    {

        int curx = q.front().x;
        int cury = q.front().y;
        int curtime = q.front().times;
        q.pop();

        if (arr[curx][cury] == 'L')
        {
            return curtime;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && arr[nx][ny] != 'X')
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, curtime + 1});
                }
            }
        }
    }
    return -1;
}

int bfs()
{
    queue<Node> q;
    visited[lx][ly] = true;
    q.push({lx, ly, 0});
    while (!q.empty())
    {

        int curx = q.front().x;
        int cury = q.front().y;
        int curtime = q.front().times;
        q.pop();
        if (arr[curx][cury] == 'E')
        {
            return curtime;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && arr[nx][ny] != 'X')
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, curtime + 1});
                }
            }
        }
    }
    return -1;
}
int solution(vector<string> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = maps[i][j];
            if (arr[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (arr[i][j] == 'L')
            {
                lx = i;
                ly = j;
            }
        }
    }
    int ans1 = laverBfs();
    if (ans1 == -1)
    {
        return -1;
    }

    memset(visited, false, sizeof(visited));
    int ans2 = bfs();
    if (ans2 == -1)
    {
        return -1;
    }
    answer = ans1 + ans2;
    return answer;
}