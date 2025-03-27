#include <bits/stdc++.h>
using namespace std;

#define Large 5
#define Small 3

class Board
{
public:
    int a[Large][Large];

private:
    bool inRange(int y, int x)
    {
        return 0 <= y && y < Large && 0 <= x && x < Large;
    }

public:
    Board()
    {
        for (int i = 0; i < Large; i++)
        {
            for (int j = 0; j < Large; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    Board *Rotate(int sy, int sx, int cnt)
    {
        Board *result = new Board();
        for (int i = 0; i < Large; i++)
        {
            for (int j = 0; j < Large; j++)
            {
                result->a[i][j] = a[i][j];
            }
        }
        for (int k = 0; k < cnt; k++)
        {
            int temp[3][3];
            for (int i = 0; i < Small; i++)
            {
                for (int j = 0; j < Small; j++)
                {
                    temp[i][j] = result->a[sy + i][sx + j];
                }
            }
            for (int i = 0; i < Small; i++)
            {
                for (int j = 0; j < Small; j++)
                {
                    result->a[sy + j][sx + Small - 1 - i] = temp[i][j];
                }
            }
        }
        return result;
    }

    int CalScore()
    {
        int score = 0;
        bool visited[Large][Large];
        for (int i = 0; i < Large; i++)
        {
            for (int j = 0; j < Large; j++)
            {
                visited[i][j] = false;
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < Large; i++)
        {
            for (int j = 0; j < Large; j++)
            {
                if (!visited[i][j])
                {
                    queue<pair<int, int>> q, trace;
                    q.push({i, j});
                    trace.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int ny = cur.first + dy[k];
                            int nx = cur.second + dx[k];
                            if (inRange(ny, nx) && a[ny][nx] == a[cur.first][cur.second] && !visited[ny][nx])
                            {
                                q.push({ny, nx});
                                trace.push({ny, nx});
                                visited[ny][nx] = true;
                            }
                        }
                    }
                    if (trace.size() >= 3)
                    {
                        score += trace.size();
                        while (!trace.empty())
                        {
                            pair<int, int> t = trace.front();
                            trace.pop();
                            a[t.first][t.second] = 0;
                        }
                    }
                }
            }
        }
        return score;
    }

    void Fill(queue<int> *que)
    {
        // 열이 작고 행이 큰 우선순위로 채워줌
        for (int j = 0; j < Large; j++)
        {
            for (int i = Large - 1; i >= 0; i--)
            {
                if (a[i][j] == 0)
                {
                    a[i][j] = que->front();
                    que->pop();
                }
            }
        }
    }
};

int main()
{
    int m, k;
    queue<int> q;
    Board *board = new Board();
    cin >> k >> m;

    for (int i = 0; i < Large; i++)
    {
        for (int j = 0; j < Large; j++)
        {
            cin >> board->a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        q.push(t);
    }
    while (k--)
    {
        int maxScore = 0;
        Board *maxScoreBoard = NULL;
        // 유물 획득 가치 큰거
        // 회전 각도 작은거
        // 열 작은거 -> 행 작은거

        // 왼쪽 상단부터 3*3격자
        for (int cnt = 1; cnt <= 3; cnt++)
        {
            for (int sx = 0; sx <= Large - Small; sx++)
            {
                for (int sy = 0; sy <= Large - Small; sy++)
                {
                    Board *rotated = board->Rotate(sy, sx, cnt);
                    int score = rotated->CalScore();
                    if (maxScore < score)
                    {
                        maxScore = score;
                        maxScoreBoard = rotated;
                    }
                }
            }
        }

        if (maxScoreBoard == NULL)
        {
            break;
        }

        board = maxScoreBoard;

        while (true)
        {
            board->Fill(&q);
            int newScore = 0;
            newScore = board->CalScore();
            if (newScore == 0)
            {
                break;
            }
            maxScore += newScore;
        }
        cout << maxScore << " ";
    }
}