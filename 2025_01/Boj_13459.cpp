#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[11][11];
bool visited[11][11][11][11];
int bx, by, rx, ry;
int ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
struct State
{
    int rx, ry, bx, by, moves;
};
void bfs()
{
    queue<State> q;
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;
    while (!q.empty())
    {
        State cur = q.front();
        q.pop();
        // 10번 이상 이동한 경우
        if (cur.moves > 10)
        {
            ans = -1;
            return;
        }

        // 빨간색 공이 구멍에 빠진 경우
        if (arr[cur.rx][cur.ry] == 'O' && arr[cur.bx][cur.by] != 'O')
        {
            ans = cur.moves;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nrx = cur.rx;
            int nry = cur.ry;
            int nbx = cur.bx;
            int nby = cur.by;
            // 빨간공 이동
            while (arr[nrx + dx[i]][nry + dy[i]] != '#' && arr[nrx][nry] != 'O')
            {
                nrx += dx[i];
                nry += dy[i];
            }
            // 파란공 이동
            while (arr[nbx + dx[i]][nby + dy[i]] != '#' && arr[nbx][nby] != 'O')
            {
                nbx += dx[i];
                nby += dy[i];
            }

            // 파란공이 구멍에 빠진 경우
            if (arr[nbx][nby] == 'O')
            {
                ans = -1;
                continue;
            }
            // * 두공이 같은 위치에 있는경우 -> 이동거리가 긴 친구가 뒤로!
            if (nbx == nrx && nby == nry)
            {
                if (abs(nrx - cur.rx) + abs(nry - cur.ry) > abs(nbx - cur.bx) + abs(nby - cur.by))
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            // 방문하지 않은경우
            if (!visited[nrx][nry][nbx][nby])
            {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, cur.moves + 1});
            }
        }
    }
    ans = -1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'R')
            {
                rx = i;
                ry = j;
            }
            else if (s[j] == 'B')
            {
                bx = i;
                by = j;
            }
            arr[i][j] = s[j];
        }
    }
    bfs();

    if (ans == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
}