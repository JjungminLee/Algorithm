#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[11][11];
bool visited[11][11][11][11];
int rx, ry;
int bx, by;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char returnChar(int idx)
{
    char ch;
    switch (idx)
    {
    case 0:
        return 'U';
    case 1:
        return 'D';

    case 2:
        return 'L';

    case 3:
        return 'R';
    }
    return '\0';
}

bool checkRange(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}
struct State
{
    int rx, ry, bx, by, moves;
    string str;
};
void bfs()
{
    queue<State> q;
    q.push({rx, ry, bx, by, 0, ""});
    visited[rx][ry][bx][by] = true;
    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        if (cur.moves > 10)
        {

            cout << -1 << endl;
            return;
        }
        // 빨간 공이 구멍에 들어감
        if (arr[cur.rx][cur.ry] == 'O' && arr[cur.bx][cur.by] != 'O')
        {

            cout << cur.moves << endl;
            cout << cur.str << endl;
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

            // 파란공이 먼저 들어가면
            if (arr[nbx][nby] == 'O')
            {
                continue;
            }
            // 겹치면 -> 더 많이 이동한게 한칸 뒤로
            if (nbx == nrx && nry == nby)
            {
                if (abs(nbx - cur.bx) + abs(nby - cur.by) < abs(nrx - cur.rx) + abs(nry - cur.ry))
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

            // 방문안하면 추가해주기
            if (!visited[nrx][nry][nbx][nby])
            {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, cur.moves + 1, cur.str + returnChar(i)});
            }
        }
    }

    cout << -1 << endl;
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = str[j];
            if (arr[i][j] == 'R')
            {
                rx = i;
                ry = j;
            }
            if (arr[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }
    bfs();
}