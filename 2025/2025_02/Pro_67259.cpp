#include <bits/stdc++.h>
using namespace std;
int money = INT_MAX;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dijkstra(int n, vector<vector<int>> board)
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    int cost[26][26][4];
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cost[i][j][k] = INT_MAX;
            }
        }
    }
    if (board[1][0] == 0)
    {
        q.push({{1, 0}, {2, 100}});
        cost[1][0][2] = 100;
    }
    if (board[0][1] == 0)
    {
        q.push({{0, 1}, {3, 100}});
        cost[1][0][3] = 100;
    }

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int direction = q.front().second.first;
        int amount = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nAmount = amount;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 0)
            {
                if ((direction % 2) == (i % 2))
                {
                    nAmount += 100;
                }
                else
                {
                    nAmount += 600;
                }
                if (cost[nx][ny][i] > nAmount)
                {
                    cost[nx][ny][i] = nAmount;
                    q.push({{nx, ny}, {i, nAmount}});
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        money = min(money, cost[n - 1][n - 1][i]);
    }
}
int solution(vector<vector<int>> board)
{
    int answer = 0;
    dijkstra(board.size(), board);
    answer = money;
    return answer;
}