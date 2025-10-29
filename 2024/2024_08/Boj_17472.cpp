#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[11][11];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int parent[11];
bool visited[11][11];
int marking = 1;
int ans[11][11];
vector<tuple<int, int, int>> edges;

void makeBridge()
{
    // 가로 방향 (열 방향)
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
                    // 같은 다리를 만나는 경우
                    if (arr[i][k] == startIsland)
                        break;
                    if (arr[i][k] > 0)
                    {
                        if (len > 1)
                        {
                            int endIsland = arr[i][k];
                            edges.push_back({len, startIsland, endIsland});
                        }
                        break;
                    }
                    len++;
                }
            }
        }
    }

    // 세로 방향 (행 방향)
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
                        break;
                    if (arr[k][j] > 0)
                    {
                        if (len > 1)
                        {
                            int endIsland = arr[k][j];
                            edges.push_back({len, startIsland, endIsland});
                        }
                        break;
                    }
                    len++;
                }
            }
        }
    }
}

void distinctLand(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    arr[x][y] = marking;
    while (!q.empty())
    {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = qx + dx[k];
            int ny = qy + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (arr[nx][ny] == 1 && !visited[nx][ny])
                {
                    arr[nx][ny] = marking;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    marking++;
}

int find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unions(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x < y)
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}

bool checkConnected()
{
    int root = find(1);
    for (int i = 2; i < marking; i++)
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
    sort(edges.begin(), edges.end());
    int totalCost = 0;
    for (auto &edge : edges)
    {
        int len, u, v;
        tie(len, u, v) = edge;
        if (find(u) != find(v))
        {
            unions(u, v);
            totalCost += len;
        }
    }
    if (checkConnected())
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
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                distinctLand(i, j);
            }
        }
    }

    makeBridge();

    for (int i = 1; i < marking; i++)
    {
        parent[i] = i;
    }

    kruskal();

    return 0;
}
