#include <bits/stdc++.h>

using namespace std;
// l r u d
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> moving(string cmd, int x, int y)
{
    int nx = 0;
    int ny = 0;
    if (cmd == "left")
    {
        nx = x + dx[0];
        ny = y + dy[0];
    }
    else if (cmd == "right")
    {
        nx = x + dx[1];
        ny = y + dy[1];
    }
    else if (cmd == "up")
    {
        nx = x + dx[2];
        ny = y + dy[2];
    }
    else if (cmd == "down")
    {
        nx = x + dx[3];
        ny = y + dy[3];
    }
    return {nx, ny};
}

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    vector<int> answer;
    int x = 0;
    int y = 0;
    int bx = board[0] / 2;
    int by = board[1] / 2;
    for (int i = 0; i < keyinput.size(); i++)
    {
        pair<int, int> cur = moving(keyinput[i], x, y);
        if (cur.first >= (bx * -1) && cur.first <= bx && cur.second >= (by * -1) && cur.second <= by)
        {
            x = cur.first;
            y = cur.second;
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}