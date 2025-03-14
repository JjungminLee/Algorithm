#include <bits/stdc++.h>
using namespace std;
int n, m, d;
int arr[16][16];
vector<vector<int>> combinations;
int dx[3] = {0, -1, 0}; // 왼 오 위
int dy[3] = {-1, 0, 1};
int ans;

bool findAllEnemyDie(int map[16][16])
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                flag = false;
                return flag;
            }
        }
    }
    return flag;
}
/*
궁수의 조합 만들기
@todo: 이거 자체 정리하기
*/
void combinationVector(int curr, int start, vector<int> v)
{
    if (curr == 3)
    {
        combinations.push_back(v);
    }
    for (int i = start; i < m; i++)
    {
        v.push_back(i);
        combinationVector(curr + 1, i + 1, v); // i+1이 핵심
        v.pop_back();
    }
}

/*
 궁수가 공격하는 적은 거리가 D이하인 적 중에서 가장 가까운 적 찾는데, 여러개일 경우, 왼쪽에 있는거
*/
pair<int, int> bfs(int x, int y, int map[16][16])
{
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {x, y}});
    bool visited[16][16] = {
        false,
    };
    visited[x][y] = true;
    while (!q.empty())
    {
        int dist = q.front().first;
        int xx = q.front().second.first;
        int yy = q.front().second.second;

        q.pop();

        if (dist > d)
        {
            continue;
        }
        if (map[xx][yy] == 1)
        {

            return {xx, yy};
        }

        for (int i = 0; i < 3; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
            {

                visited[nx][ny] = true;
                q.push({dist + 1, {nx, ny}});
            }
        }
    }

    return {-1, -1};
}

void moveEnemy(int map[16][16])
{
    int backup[16][16] = {
        0,
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                if (i + 1 < n)
                {
                    backup[i + 1][j] = map[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = backup[i][j];
        }
    }
}

int main()
{
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> v;
    combinationVector(0, 0, v);

    for (int i = 0; i < combinations.size(); i++)
    {
        int map[16][16] = {
            0,
        };
        memcpy(map, arr, sizeof(arr));

        int backup[16][16] = {
            0,
        };
        memcpy(backup, arr, sizeof(arr));
        vector<int> comb = combinations[i];

        int cnt = 0;
        while (true)
        {

            set<pair<int, int>> deleteEnemy;

            if (findAllEnemyDie(map))
            {
                break;
            }

            for (int j = 0; j < 3; j++)
            {
                pair<int, int> p = bfs(n, comb[j], map);
                if (p.first != -1 && p.second != -1)
                {
                    deleteEnemy.insert(p);
                }
            }
            cout << "-----" << endl;
            for (auto it = deleteEnemy.begin(); it != deleteEnemy.end(); it++)
            {
                int x = it->first;
                int y = it->second;

                if (map[x][y] == 1)
                {
                    map[x][y] = 0;
                    cnt++;
                }
            }

            int backup2[16][16] = {
                0,
            };
            moveEnemy(map);
        }
        // 조합마다 최소값
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}