#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[11][11];
bool visited[11][11][11][11];
int rx, ry, bx, by;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
struct State
{
    int rx, ry, bx, by, moves;
    string str;
};
char returnChar(int i)
{
    if (i == 0)
    {
        return 'U';
    }
    else if (i == 1)
    {
        return 'D';
    }
    else if (i == 2)
    {
        return 'L';
    }
    else if (i == 3)
    {
        return 'R';
    }
    return '\0';
}
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
            while (arr[nrx + dx[i]][nry + dy[i]] != '#' && arr[nrx][nry] != 'O')
            {
                nrx += dx[i];
                nry += dy[i];
            }
            while (arr[nbx + dx[i]][nby + dy[i]] != '#' && arr[nbx][nby] != 'O')
            {
                nbx += dx[i];
                nby += dy[i];
            }
            if (arr[nbx][nby] == 'O')
            {
                continue;
            }
            if (nbx == nrx && nby == nry)
            {
                if (abs(nrx - cur.rx) + abs(nry - cur.ry) < abs(nbx - cur.bx) + abs(nby - cur.by))
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
                else
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
            }
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