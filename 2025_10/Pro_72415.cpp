#include <bits/stdc++.h>

using namespace std;

int dr[4] = {0, -1, 1, 0};
int dc[4] = {-1, 0, 0, 1};

bool isEnd(vector<vector<int>> board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

int bfs(vector<vector<int>> board, int sr, int sc, int er, int ec)
{
    queue<pair<int, pair<int, int>>> q;
    bool visited[4][4] = {
        false,
    };
    visited[sr][sc] = true;
    q.push({0, {sr, sc}});
    int cnt = 0;

    while (!q.empty())
    {
        auto [cnt, cur] = q.front();
        int cr = cur.first;
        int cc = cur.second;
        q.pop();
        if (cr == er && cc == ec)
        {
            return cnt;
        }
        for (int i = 0; i < 4; i++)
        {
            // 한칸 이동
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4)
            {
                if (!visited[nr][nc])
                {
                    q.push({cnt + 1, {nr, nc}});
                    visited[nr][nc] = true;
                }
            }

            nr = cr;
            nc = cc;
            // ctrl 현재 방향에서 끝까지 이동해보기 (범위 넘어서는 or 벽까지)
            while (1)
            {
                int tr = nr + dr[i];
                int tc = nc + dc[i];
                if (tr < 0 || tr >= 4 || tc < 0 || tc >= 4)
                    break;
                nr = tr;
                nc = tc;
                if (board[nr][nc] != 0)
                    break;
            }
            if (!visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({cnt + 1, {nr, nc}});
            }
        }
    }
    return INT_MAX;
}

int solution(vector<vector<int>> board, int r, int c)
{
    int answer = INT_MAX;
    map<int, vector<pair<int, int>>> mp;
    vector<int> kinds;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != 0)
            {
                mp[board[i][j]].push_back({i, j});
            }
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        kinds.push_back(it->first);
    }
    sort(kinds.begin(), kinds.end());
    do
    {
        vector<vector<int>> cur = board;
        int total = 0;
        int cr = r;
        int cc = c;
        for (int k : kinds)
        {
            auto a = mp[k][0];
            auto b = mp[k][1];

            // a->b
            int d1 = bfs(cur, cr, cc, a.first, a.second);
            int d2 = bfs(cur, a.first, a.second, b.first, b.second);
            int dist1 = d1 + d2 + 2; // 엔터

            int d3 = bfs(cur, cr, cc, b.first, b.second);
            int d4 = bfs(cur, b.first, b.second, a.first, a.second);
            int dist2 = d3 + d4 + 2; // 엔터

            if (dist1 < dist2)
            {
                total += dist1;
                cr = b.first;
                cc = b.second;
            }
            else
            {
                total += dist2;
                cr = a.first;
                cc = a.second;
            }
            cur[a.first][a.second] = 0;
            cur[b.first][b.second] = 0;
        }
        answer = min(answer, total);
    } while (next_permutation(kinds.begin(), kinds.end()));

    return answer;
}