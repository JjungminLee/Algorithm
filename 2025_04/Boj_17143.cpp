#include <bits/stdc++.h>
using namespace std;

int R, C, M;
int dx[4] = {-1, 1, 0, 0}; // ↑↓→←
int dy[4] = {0, 0, 1, -1};

struct State
{
    int r, c, s, d, z;
};
int ans = 0;
vector<State> v;

int switchDir(int num)
{
    switch (num)
    {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 3;
    case 3:
        return 2;
    }
    return 0;
}

void moving(State &state)
{
    int r = state.r - 1;
    int c = state.c - 1;
    int d = state.d - 1;
    int s = state.s;

    // 위 아래 일때는 행의 끝까지!
    if (d == 0 || d == 1)
        s %= (2 * (R - 1));
    else
        // 왼 오 일때는 열의 끝까지!
        s %= (2 * (C - 1));

    while (s--)
    {
        int nr = r + dx[d];
        int nc = c + dy[d];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
        {
            d = switchDir(d);
            nr = r + dx[d];
            nc = c + dy[d];
        }
        r = nr;
        c = nc;
    }

    state.r = r + 1;
    state.c = c + 1;
    state.d = d + 1;
}

int findSharkByFisher(int col)
{
    for (int row = 1; row <= R; row++)
    {
        for (State &shark : v)
        {
            if (shark.z > 0 && shark.r == row && shark.c == col)
            {
                int res = shark.z;
                shark.z = 0;
                return res;
            }
        }
    }
    return 0;
}

int main()
{
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        v.push_back({r, c, s, d, z});
    }

    for (int col = 1; col <= C; col++)
    {
        // 1. 상어 잡기
        ans += findSharkByFisher(col);

        // 2. 상어 이동
        for (State &shark : v)
        {
            if (shark.z > 0)
                moving(shark);
        }

        // 3. 겹치는 상어 처리 (큰 상어만 남기기)
        vector<vector<int>> board(R + 1, vector<int>(C + 1, -1));
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].z == 0)
                continue;
            int r = v[i].r;
            int c = v[i].c;
            if (board[r][c] == -1)
            {
                board[r][c] = i;
            }
            else
            {
                int prev = board[r][c];
                if (v[prev].z < v[i].z)
                {
                    v[prev].z = 0;
                    board[r][c] = i;
                }
                else
                {
                    v[i].z = 0;
                }
            }
        }
    }

    cout << ans << endl;
}
