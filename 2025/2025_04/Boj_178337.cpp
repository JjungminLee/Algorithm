#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[13][13];

struct State
{
    int r, c, d;
};
vector<State> v;

int dx[4] = {0, 0, -1, 1}; // 0: →, 1: ←, 2: ↑, 3: ↓
int dy[4] = {1, -1, 0, 0};
vector<int> boardStacks[13][13];
int curTurn;
int switchDir(int d)
{
    if (d == 0)
        return 1;
    if (d == 1)
        return 0;
    if (d == 2)
        return 3;
    return 2;
}

void movePiece(int r, int c, int nr, int nc, int idx, int color)
{
    auto it = find(boardStacks[r][c].begin(), boardStacks[r][c].end(), idx);
    vector<int> moving(it, boardStacks[r][c].end());

    if (color == 1)
    {
        reverse(moving.begin(), moving.end());
    }

    for (int m : moving)
    {
        boardStacks[nr][nc].push_back(m);
        v[m].r = nr;
        v[m].c = nc;
    }

    if (boardStacks[nr][nc].size() >= 4)
    {
        cout << curTurn << '\n';
        exit(0);
    }

    boardStacks[r][c].erase(it, boardStacks[r][c].end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < k; i++)
    {
        int r, c, d;
        cin >> r >> c >> d;
        boardStacks[r - 1][c - 1].push_back(i);
        v.push_back({r - 1, c - 1, d - 1});
    }

    for (curTurn = 1; curTurn <= 1000; curTurn++)
    {
        for (int i = 0; i < k; i++)
        {
            int r = v[i].r, c = v[i].c;
            int d = v[i].d;

            int nr = r + dx[d], nc = c + dy[d];

            // 파란색 또는 밖이면 방향 전환
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || arr[nr][nc] == 2)
            {
                d = switchDir(d);
                v[i].d = d;
                nr = r + dx[d];
                nc = c + dy[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || arr[nr][nc] == 2)
                    continue;
            }

            movePiece(r, c, nr, nc, i, arr[nr][nc]);
        }
    }

    cout << -1 << "\n";
    return 0;
}
