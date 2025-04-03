#include <bits/stdc++.h>
int R, C, M;
struct State
{
    int r, c, s, d, z;
};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<State> v;
int fishingShark(int col)
{
    for (int row = 1; row <= R; row++)
    {
        for (State &st : v)
        {
            if (st.z > 0 && st.r == row && st.c == col)
            {
                int returnZ = st.z;
                st.z = 0;
                return returnZ;
            }
        }
    }
    return 0;
}
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
void moving(State &st)
{
    int r = st.r - 1;
    int c = st.c - 1;
    int s = st.s;
    int d = st.d - 1;
    int z = st.z;

    // 속력값이 너무 크게 나올때 줄여주기 위함
    if (d == 1 || d == 0)
    {
        s %= (2 * (R - 1));
    }
    else
    {
        s %= (2 * (C - 1));
    }
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
    st.r = r + 1;
    st.c = c + 1;
    st.d = d + 1;
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
    int ans = 0;
    for (int i = 1; i <= C; i++)
    {
        // 낚시왕 같은 열에 있는 근데 행은 가장 작은 물고기 잡기
        ans += fishingShark(i);
        // 상어 움직이기
        for (State &st : v)
        {
            if (st.z > 0)
            {
                moving(st);
            }
        }
        // 같은칸에 상어 여러개면 상어 먹기
        vector<vector<int>> board(R + 1, vector<int>(C + 1, -1));
        for (int k = 0; k < v.size(); k++)
        {
            if (v[k].z <= 0)
            {
                continue;
            }
            int r = v[k].r;
            int c = v[k].c;
            if (board[r][c] == -1)
            {
                board[r][c] = k;
            }
            else
            {
                int prev = board[r][c];
                if (v[prev].z >= v[k].z)
                {
                    v[k].z = 0;
                }
                else
                {
                    v[prev].z = 0;
                    board[r][c] = k;
                }
            }
        }
    }
}