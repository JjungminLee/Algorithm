#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<tuple<int, int, int>> v;
int arr[11][11];
bool visited[11][11];
int parents[11];
int marking = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int a, int b)
{
    marking++;
    queue<pair<int, int>> q;
    visited[a][b] = true;
    q.push({a, b});
    arr[a][b] = marking;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!visited[nx][ny] && arr[nx][ny] == 1)
                {
                    arr[nx][ny] = marking;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void makeBridge()
{
    // 가로 기준으로
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > 0)
            {

                int startIsland = arr[i][j];
                int len = 0;
                for (int k = j + 1; k < m; k++)
                {
                    if (arr[i][k] == startIsland)
                    {
                        break;
                    }
                    if (arr[i][k] > 0)
                    {
                        if (len > 1)
                        {
                            int endIsland = arr[i][k];
                            v.push_back({len, startIsland, endIsland});
                        }
                        break;
                    }
                    len++;
                }
            }
        }
    }

    // 세로 기준으로
    for (int j = 0; j < m; j++)
    {

        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] > 0)
            {
                int startIsland = arr[i][j];
                int len = 0;
                for (int k = i + 1; k < n; k++)
                {
                    if (arr[k][j] == startIsland)
                    {
                        break;
                    }
                    if (arr[k][j] > 0)
                    {
                        if (len > 1)
                        {
                            int endIsland = arr[k][j];
                            v.push_back({len, startIsland, endIsland});
                        }
                        break;
                    }
                    len++;
                }
            }
        }
    }
}

int find(int a)
{
    if (a == parents[a])
    {
        return a;
    }
    return parents[a] = find(parents[a]);
}
void unions(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x < y)
    {
        parents[y] = x;
    }
    else
    {
        parents[x] = y;
    }
}

// 루트와 이어져 있는지 확인
bool connection()
{
    int root = find(1);
    for (int i = 2; i <= marking; i++)
    {
        if (find(i) != root)
        {
            return false;
        }
    }
    return true;
}

void kruskal()
{
    sort(v.begin(), v.end());
    int totalCost = 0;
    for (auto &a : v)
    {
        int len, x, y;
        tie(len, x, y) = a;
        if (find(x) != find(y))
        {
            unions(x, y);
            totalCost += len;
        }
    }
    if (connection())
    {
        cout << totalCost << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    for (int i = 0; i < 11; i++)
    {
        parents[i] = i;
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    /*bfs로 섬 라벨링*/

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                bfs(i, j);
            }
        }
    }
    /*다리 만들기*/
    makeBridge();
    /*크루스칼로 최소비용 다리만 고르기*/
    kruskal();
}