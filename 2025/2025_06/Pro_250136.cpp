#include <bits/stdc++.h>

using namespace std;
bool visited[501][501];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y, int n, int m, vector<vector<int>> &land, int idx)
{
    int temp = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    land[x][y] = idx;
    temp++;

    while (!q.empty())
    {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && land[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    land[nx][ny] = idx;
                    q.push({nx, ny});
                    land[nx][ny] = idx;
                    temp++;
                }
            }
        }
    }
    return temp;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    int idx = 2;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && land[i][j] == 1)
            {
                int temp = bfs(i, j, n, m, land, idx);
                mp[idx] = temp;
                idx++;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            if (land[i][j] != 0)
            {
                st.insert({land[i][j]});
            }
        }
        int tmp = 0;
        for (auto it = st.begin(); it != st.end(); it++)
        {

            tmp += mp[*it];
        }
        answer = max(tmp, answer);
    }

    return answer;
}