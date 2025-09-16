#include <bits/stdc++.h>
using namespace std;

// 키패드 배치
int board[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {-1, 0, -1}};

// 상하좌우(2), 대각(3)
int ddx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int ddy[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int wgt[8] = {2, 2, 2, 2, 3, 3, 3, 3};

struct Node
{
    int v;
    int c;
    bool operator<(const Node &o) const { return c > o.c; }
};

static inline bool inside(int x, int y)
{
    return (0 <= x && x < 4 && 0 <= y && y < 3 && board[x][y] != -1);
}

// 각 숫자(0~9) 쌍 사이 최단 비용 (자기 자신 재입력 비용 = 1)
array<array<int, 10>, 10> build_cost()
{
    array<array<int, 10>, 10> cost;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cost[i][j] = (i == j ? 1 : 1e9);

    // 좌표 -> 숫자, 숫자 -> 좌표
    pair<int, int> pos[10];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != -1)
            {
                pos[board[i][j]] = {i, j};
            }
        }
    }

    // 그래프 인접 리스트 구성 (노드: 0~9)
    vector<vector<pair<int, int>>> g(10);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == -1)
                continue;
            int u = board[i][j];
            for (int k = 0; k < 8; k++)
            {
                int nx = i + ddx[k], ny = j + ddy[k];
                if (inside(nx, ny))
                {
                    int v = board[nx][ny];
                    g[u].push_back({v, wgt[k]});
                }
            }
        }
    }

    // 각 시작 숫자에 대해 다익스트라 (가중치 2/3)
    for (int s = 0; s < 10; s++)
    {
        vector<int> dist(10, 1e9);
        priority_queue<Node> pq;
        dist[s] = 0;
        pq.push({s, 0});
        while (!pq.empty())
        {
            auto [u, c] = pq.top();
            pq.pop();
            if (c != dist[u])
                continue;
            for (auto [v, w] : g[u])
            {
                if (dist[v] > c + w)
                {
                    dist[v] = c + w;
                    pq.push({v, dist[v]});
                }
            }
        }
        for (int t = 0; t < 10; t++)
        {
            if (s == t)
                cost[s][t] = 1; // 제자리 재입력
            else
                cost[s][t] = dist[t];
        }
    }
    return cost;
}

int solution(string numbers)
{
    // 1) 이동 비용 전처리
    auto cost = build_cost();

    // 2) DP: dp[l][r] = 현재 왼손 l, 오른손 r 일 때의 최소 비용
    const int INF = 1e9;
    static int dp[10][10], ndp[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            dp[i][j] = INF;

    // 시작 위치: 왼손 4, 오른손 6
    dp[4][6] = 0;

    for (char ch : numbers)
    {
        int d = ch - '0';
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                ndp[i][j] = INF;

        for (int l = 0; l < 10; l++)
        {
            for (int r = 0; r < 10; r++)
            {
                int cur = dp[l][r];
                if (cur == INF)
                    continue;
                if (l == r)
                    continue; // 두 손가락이 같은 키에 있을 수 없음 (불변 조건 유지)

                // (1) 반드시 같은 손가락으로 눌러야 하는 경우
                if (d == l)
                {
                    // 왼손 그대로 눌러서 비용 +1 (cost[l][l])
                    // 상태는 (l, r) 그대로
                    ndp[l][r] = min(ndp[l][r], cur + cost[l][l]);
                    continue;
                }
                if (d == r)
                {
                    ndp[l][r] = min(ndp[l][r], cur + cost[r][r]);
                    continue;
                }

                // (2) 선택지: 왼손을 d로 이동
                if (d != r)
                { // 이동 후에도 겹치지 않아야 함
                    ndp[d][r] = min(ndp[d][r], cur + cost[l][d]);
                }
                // (3) 선택지: 오른손을 d로 이동
                if (d != l)
                {
                    ndp[l][d] = min(ndp[l][d], cur + cost[r][d]);
                }
            }
        }
        // swap
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                dp[i][j] = ndp[i][j];
    }

    int ans = INF;
    for (int l = 0; l < 10; l++)
        for (int r = 0; r < 10; r++)
            if (l != r)
                ans = min(ans, dp[l][r]);
    return ans;
}
