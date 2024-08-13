#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[11][11];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int parent[11];
int visited[11][11];
int marking = 1;
int ans[11][11];
int ansNum;
vector<tuple<int, int, int>> v;

void makeBridge()
{
    // 가로 방향 (열 방향)
    for (int i = 0; i < n; i++)
    {
        int startIsland = 0;
        int len = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= 1)
            {
                if (startIsland == 0)
                {
                    startIsland = arr[i][j];
                }
                else if (arr[i][j] != startIsland)
                {
                    int endIsland = arr[i][j];
                    if (len > 1 && ans[startIsland][endIsland] > len)
                    { // 다리 길이가 2 이상인 경우에만 갱신
                        ans[startIsland][endIsland] = len;
                        ans[endIsland][startIsland] = len;
                    }
                    startIsland = arr[i][j];
                    len = 0; // 길이 초기화
                }
                else
                {
                    len = 0; // 같은 섬인 경우 길이를 초기화
                }
            }
            else if (startIsland > 0 && arr[i][j] == 0)
            {
                len++;
            }
        }
    }

    // 세로 방향 (행 방향)
    for (int i = 0; i < m; i++)
    {
        int startIsland = 0;
        int len = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] >= 1)
            {
                if (startIsland == 0)
                {
                    startIsland = arr[j][i];
                }
                else if (arr[j][i] != startIsland)
                {
                    int endIsland = arr[j][i];
                    if (len > 1 && ans[startIsland][endIsland] > len)
                    {
                        ans[startIsland][endIsland] = len;
                        ans[endIsland][startIsland] = len;
                    }
                    startIsland = arr[j][i];
                    len = 0;
                }
                else
                {
                    len = 0;
                }
            }
            else if (startIsland > 0 && arr[j][i] == 0)
            {
                len++;
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
bool check(int a, int b)
{ // 같은 부모를 가지는지 확인(=사이클인 경우)
    a = find(a);
    b = find(b);
    if (a == b)
        return true;
    else
        return false;
}
void kruskal()
{
    int totalCost = 0;
    for (auto &a : v)
    {
        int len, x, y;
        tie(len, x, y) = a;
        // 같은 그룹이 아니라면 (사이클이 일어나지 않아야하며 모든 노드를 방문가능헤야함!)
        if (find(x) != find(y))
        {
            unions(x, y);
            totalCost += len;
        }
    } // 모든 섬이 연결되었는지 확인
    int firstParent = find(parent[1]);
    for (int i = 1; i <= marking - 1; i++) // n * m을 marking - 1로 변경
    {
        if (parent[i] != 0 && find(i) != firstParent)
        {
            cout << -1 << endl; // 모든 섬이 연결되지 않았다.
            return;
        }
    }
    cout << totalCost << endl;
}
int main()
{
    for (int i = 0; i < 11; i++)
    {
        parent[i] = i;
    }
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            ans[i][j] = 1000;
        }
    }
    /*bfs로 섬 구획하기*/
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

    /*다리 만들기*/
    makeBridge();
    for (int i = 1; i <= marking; i++)
    {
        for (int j = 1; j <= marking; j++)
        {
            if (ans[i][j] != 1000)
            {
                v.push_back({ans[i][j], i, j});
            }
        }
    }
    /* 크루스칼*/
    // 간선을 오름차순으로 정렬
    sort(v.begin(), v.end());

    kruskal();
}
