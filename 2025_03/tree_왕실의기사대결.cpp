#include <bits/stdc++.h>
using namespace std;

int L, N, Q;
int arr[41][41];

struct State
{
    int r, c, h, w, k;
};
vector<State> v;            // 기사 정보
vector<pair<int, int>> ans; // 체력, 누적 데미지
int dx[4] = {-1, 0, 1, 0};  // 상우하좌
int dy[4] = {0, 1, 0, -1};

// 기사 i가 h*w만큼 차지하는 모든 좌표
vector<pair<int, int>> getCells(int i)
{
    vector<pair<int, int>> res;
    for (int r = v[i].r; r < v[i].h + v[i].r; r++)
    {
        for (int c = v[i].c; c < v[i].w + v[i].c; c++)
        {
            res.push_back({r, c});
        }
    }
    return res;
}

bool isBlocked(int i, int dir)
{
    vector<pair<int, int>> nv = getCells(i);
    for (int i = 0; i < nv.size(); i++)
    {
        int nx = nv[i].first + dx[dir];
        int ny = nv[i].second + dy[dir];
        if (nx < 0 || nx >= L || ny < 0 || ny >= L)
        {
            return true;
        }
        if (arr[nx][ny] == 2)
        {
            return true;
        }
    }
    return false;
}

int findCollision(int r, int c)
{
    for (int i = 0; i < N; i++)
    {
        if (ans[i].first <= 0)
        {
            continue;
        }
        vector<pair<int, int>> nv = getCells(i);
        for (int j = 0; j < nv.size(); j++)
        {
            // 이동한 위치에 이미 기사가 있는지 확인
            if (nv[j].first == r && nv[j].second == c)
            {
                return i;
            }
        }
    }
    return -1;
}

void moving(int idx, int dir)
{
    idx--;
    if (ans[idx].first <= 0)
    {
        return;
    }
    queue<int> q;
    set<int> group;
    q.push(idx);
    group.insert(idx);

    // 연쇄적으로 밀리는건 bfs 활용
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        // 현 위치에서 h*w만큼 탐색
        vector<pair<int, int>> nv = getCells(cur);
        for (int i = 0; i < nv.size(); i++)
        {
            int nx = nv[i].first + dx[dir];
            int ny = nv[i].second + dy[dir];
            int other = findCollision(nx, ny);
            // 충돌된 사람이 이미 set에 포함되지 않으면 큐,set에 푸쉬
            if (other != -1 && group.find(other) == group.end())
            {
                q.push(other);
                group.insert(other);
            }
        }
    }
    // 연쇄적으로 밀린 기사가 해당 방향으로 이동가능한지 판단
    // 하나라도 벽을 만나면 모든 기사는 이동 불가능
    for (int g : group)
    {

        if (isBlocked(g, dir))
        {
            return;
        }
    }

    vector<int> damaged;
    for (int g : group)
    {
        if (g == idx)
        {
            continue;
        }
        damaged.push_back(g);
    }

    // 연쇄적으로 현재 방향만큼 이동
    for (int g : group)
    {
        v[g].r += dx[dir];
        v[g].c += dy[dir];
    }

    for (int d : damaged)
    {
        int trap = 0;
        vector<pair<int, int>> nv = getCells(d);
        for (int i = 0; i < nv.size(); i++)
        {
            if (arr[nv[i].first][nv[i].second] == 1)
            {
                trap++;
            }
        }
        if (trap > 0 || ans[d].second > 0)
        {
            ans[d].first -= trap;
            ans[d].second += trap;
            if (ans[d].first <= 0)
            {
                ans[d].first = 0;
            }
        }
    }
}

int main()
{
    cin >> L >> N >> Q;
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < L; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        int r, c, h, w, k;
        cin >> r >> c >> h >> w >> k;
        v.push_back({r - 1, c - 1, h, w, k});
        ans.push_back({k, 0});
    }

    for (int i = 0; i < Q; i++)
    {
        int k, d;
        cin >> k >> d;
        moving(k, d);
    }
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        if (ans[i].first > 0)
        {
            answer += ans[i].second;
        }
    }
    cout << answer << endl;
}