#include <bits/stdc++.h>
using namespace std;

int n, k;
struct State
{
    int r, c, d;
};
int arr[13][13];
vector<State> v;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<int> boardStacks[13][13];
int curTurn;
int switchDir(int n)
{
    switch (n)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    }
    return 2;
}

void movePiece(int r, int c, int nr, int nc, int color, int idx)
{
    auto it = find(boardStacks[r][c].begin(), boardStacks[r][c].end(), idx); // idx가 처음 있는지점
    vector<int> moving(it, boardStacks[r][c].end());                         // idx가 처음 있는 지점에서 끝까지 가져오기
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
        cout << curTurn << endl;
        exit(0);
    }
    boardStacks[r][c].erase(it, boardStacks[r][c].end());
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int r, c, d;
        cin >> r >> c >> d;
        boardStacks[r - 1][c - 1].push_back(i);
        v.push_back({r - 1, c - 1, d - 1});
    }

    // curTurn 전역
    for (curTurn = 1; curTurn <= 1000; curTurn++)
    {
        for (int i = 0; i < k; i++)
        {
            int r = v[i].r;
            int c = v[i].c;
            int d = v[i].d;

            int nr = r + dx[d];
            int nc = c + dy[d];

            // 범위 넘은거랑 파란색은 같이 생각
            // arr[nr][nc] 생각해야함
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || arr[nr][nc] == 2)
            {
                // 이동방향을 반대로하고
                d = switchDir(d);
                v[i].d = d; // 중요
                // 한칸 이동한다
                nr = r + dx[d];
                nc = c + dy[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || arr[nr][nc] == 2)
                {
                    continue;
                }
            }
            movePiece(r, c, nr, nc, arr[nr][nc], i);
        }
    }
    cout << -1 << endl;
}