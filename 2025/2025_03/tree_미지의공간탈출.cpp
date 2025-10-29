#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
const int MAXM = 20;
const int MAXF = 400;
const int MAXP = MAXF * 6;

const int INF = 1e9 + 10;

int spaceMap[MAXN + 10][MAXN + 10];          // 미지의 공간의 평면도
int spaceMapCellId[MAXN + 10][MAXN + 10];    // 평면도의 각 셀에 대응하는 그래프 정점의 번호를 저장하는 배열
int timeWall[6][MAXM + 10][MAXM + 10];       // 시간의 벽의 단면도
int timeWallCellId[6][MAXM + 10][MAXM + 10]; // 시간의 벽의 단면도의 각 셀에 대응하는 그래프 정점의 번호를 저장하는 배열

// 시간 이상 현상에 대한 정보를 저장할 구조체
struct AbnormalTimeEvent
{
    // 시간 이상 현상이 시작점의 행번호, 열번호, 방향, 확장 주기, 시간 이상 현상의 진행여부를 차례로 저장합니다
    int xpos, ypos, direction, cycle, alive;
};

AbnormalTimeEvent events[MAXF + 10];
vector<vector<int>> graph;
// 타임머신에서 해당 번호의 셀까지 도달하는데 필요한 최소 턴 횟수
int dist[MAXP];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/*
미로랑 시간의 벽을 이어줘야함
 */
void build_graph(int n, int m)
{
    int cnt = 0;

    // 1차원 배열로 변환한 셀 번호 입력하기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (spaceMap[i][j] != 3)
            {
                cnt++;
                spaceMapCellId[i][j] = cnt;
            }
        }
    }

    for (int t = 0; t < 5; t++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cnt++;
                timeWallCellId[t][i][j] = cnt;
            }
        }
    }

    // 셀 번호랑 인접한 애들 찾기 ->추후 bfs하기 위함, 인접방향은 4개(상하좌우)
    graph = vector<vector<int>>(cnt + 1, vector<int>(4, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (spaceMap[i][j] != 3)
            {
                int idx = spaceMapCellId[i][j];
                for (int dd = 0; dd < 4; dd++)
                {
                    int nx = i + dx[dd];
                    int ny = j + dy[dd];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    {
                        continue;
                    }
                    // 시간의 벽은 애초에 존재하지 않는 경로
                    if (spaceMap[nx][ny] == 3)
                    {
                        continue;
                    }
                    graph[idx][dd] = spaceMapCellId[nx][ny];
                }
            }
        }
    }
    /*
    시간의 벽 내부에서 이어주기
    */
    for (int t = 0; t < 4; t++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int idx = timeWallCellId[t][i][j];
                for (int dd = 0; dd < 4; dd++)
                {
                    int nx = i + dx[dd];
                    int ny = j + dy[dd];
                    if (nx < 0 || nx >= m)
                    {
                        continue;
                    }
                    if (ny < 0)
                    {
                        graph[idx][dd] = timeWallCellId[(t + 1) % 4][nx][m - 1];
                    }
                    else if (ny >= m)
                    {
                        graph[idx][dd] = timeWallCellId[(t + 3) % 4][nx][0];
                    }
                    else
                    {
                        graph[idx][dd] = timeWallCellId[t][nx][ny];
                    }
                }
            }
        }
    }

    /*
    위쪽 단면도
    */

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int idx = timeWallCellId[4][i][j];
            for (int dd = 0; dd < 4; dd++)
            {
                int nx = i + dx[dd];
                int ny = j + dy[dd];
                if (nx < 0 || nx >= m || ny < 0 || ny >= m)
                {
                    continue;
                }
                graph[idx][dd] = timeWallCellId[4][nx][ny];
            }
        }
    }

    /*
    위쪽이랑 인접한 동쪽 단면도
    */
    for (int i = 0; i < m; i++)
    {
        int idx = timeWallCellId[4][i][m - 1];     // 위쪽
        int idy = timeWallCellId[0][0][m - 1 - i]; // 동쪽
        graph[idx][0] = idy;
        graph[idy][3] = idx;
    }

    /*
   위쪽이랑 인접한 남쪽 단면도
   */
    for (int i = 0; i < m; i++)
    {
        int idx = timeWallCellId[4][m - 1][i]; // 위쪽
        int idy = timeWallCellId[1][0][i];     // 남쪽
        graph[idx][1] = idy;
        graph[idy][3] = idx;
    }

    /*
위쪽이랑 인접한 서쪽 단면도
  */
    for (int i = 0; i < m; i++)
    {
        int idx = timeWallCellId[4][i][0]; // 위쪽 인접
        int idy = timeWallCellId[2][0][i]; // 서쪽 인접
        graph[idx][2] = idy;
        graph[idy][3] = idx;
    }

    /*
위쪽이랑 인접한 북쪽 단면도
*/
    for (int i = 0; i < m; i++)
    {
        int idx = timeWallCellId[4][0][i]; // 위쪽
        int idy = timeWallCellId[3][0][m - 1 - i];
        graph[idx][3] = idy;
        graph[idy][3] = idx;
    }

    // 평면도에서 시간의 벽이 시작되는 곳 탐색
    int timeStartX = -1;
    int timeStartY = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (spaceMap[i][j] == 3)
            {
                timeStartX = i;
                timeStartY = j;
                break;
            }
        }
        if (timeStartX != -1)
            break;
    }
    // 시간의 벽 동서남북이랑 평면도 이어주기
    // 동쪽 단면도 (시간의 벽 오른쪽에 붙을 수 있음)
    if (timeStartY + m < n)
    {
        for (int i = 0; i < m; i++)
        {
            int idx = timeWallCellId[0][m - 1][i];
            int idy = spaceMapCellId[timeStartX + m - 1 - i][timeStartY + m];
            // 정점,방향
            graph[idx][1] = idy; // 동쪽 단면도의 아래쪽에 평면도
            graph[idy][2] = idx; // 평면도의 왼쪽(서쪽) 동쪽 단면도
        }
    }

    // 남
    if (timeStartX + m < n)
    {
        for (int i = 0; i < m; i++)
        {
            int idx = timeWallCellId[1][m - 1][i];
            int idy = spaceMapCellId[timeStartX + m][timeStartY + i];
            // 정점,방향
            graph[idx][1] = idy; // 서쪽 단면도의 아래쪽에 평면도
            graph[idy][3] = idx; // 평면도에 북쪽에 남쪽 단면도
        }
    }
    // 서
    if (timeStartY > 0)
    {
        for (int i = 0; i < m; i++)
        {
            int idx = timeWallCellId[2][m - 1][i];
            int idy = spaceMapCellId[timeStartX + i][timeStartY - 1];
            // 정점,방향
            graph[idx][1] = idy;
            graph[idy][0] = idx; // 평면도의 동쪽에 서쪽단면도
        }
    }
    // 북

    if (timeStartX > 0)
    {
        for (int i = 0; i < m; i++)
        {
            int idx = timeWallCellId[3][m - 1][i];
            int idy = spaceMapCellId[timeStartX - 1][timeStartY + m - 1 - i];
            // 정점,방향
            graph[idx][1] = idy;
            graph[idy][1] = idx; // 평면도 남쪽에 북쪽 단면도
        }
    }

    return;
}
int main()
{
    int n, m, e;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> spaceMap[i][j];
        }
    }
    // 동
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> timeWall[0][i][j];
        }
    }
    // 서
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> timeWall[2][i][j];
        }
    }

    // 남
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> timeWall[1][i][j];
        }
    }

    // 북
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> timeWall[3][i][j];
        }
    }

    // 위
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> timeWall[4][i][j];
        }
    }

    for (int i = 1; i <= e; i++)
    {
        cin >> events[i].xpos >> events[i].ypos >> events[i].direction >> events[i].cycle;
        if (events[i].direction == 1)
        {
            events[i].direction = 2;
        }
        else if (events[i].direction == 2)
        {
            events[i].direction = 1;
        }
        events[i].alive = 1;
    }

    build_graph(n, m);
    // N *N - M *M + 5 *M *M = N * N + 4 * M * M 전체-시간의벽+동서남북위(5면)
    fill(dist, dist + (n * n) + 4 * (m * m) + 1, -1);

    /*
    장애물을 INF로 처리하기
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (spaceMap[i][j] == 3)
            {
                continue;
            }
            if (spaceMap[i][j] == 1)
            {
                int idx = spaceMapCellId[i][j];
                dist[idx] = INF;
            }
        }
    }

    // 평면도에서 시간 이상현상의 시작점도 도달하기 어려움
    for (int i = 1; i <= e; i++)
    {
        int x = events[i].xpos;
        int y = events[i].ypos;
        int idx = spaceMapCellId[x][y];
        dist[idx] = INF;
    }

    // 시간이상벽에 있는 장애물도 도달하기 어려움
    for (int t = 0; t < 5; t++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (timeWall[t][i][j] == 1)
                {
                    int idx = timeWallCellId[t][i][j];
                    dist[idx] = INF;
                }
            }
        }
    }

    queue<int> q;
    int cellStart = -1;
    int cellEnd = -1;

    /*
    탈출구 찾기
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (spaceMap[i][j] == 4)
            {
                cellEnd = spaceMapCellId[i][j];
                break;
            }
        }
    }

    /*
    타임머신의 시작점 탐색 (북쪽)
    */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (timeWall[4][i][j] == 2)
            {
                cellStart = timeWallCellId[4][i][j];
                break;
            }
        }
    }
    q.push(cellStart);
    dist[cellStart] = 0;
    int runs = 1;
    while (1)
    {
        /*
        이상현상
        */
        for (int i = 1; i <= e; i++)
        {
            if (!events[i].alive)
            {
                continue;
            }
            if (runs % events[i].cycle != 0)
            {
                continue;
            }
            int nx = events[i].xpos;
            int ny = events[i].ypos;
            if (events[i].direction == 0)
            {
                ny += (runs / events[i].cycle);
            }
            else if (events[i].direction == 1)
            {
                nx += (runs / events[i].cycle);
            }
            else if (events[i].direction == 2)
            {
                ny -= (runs / events[i].cycle);
            }
            else if (events[i].direction == 3)
            {
                nx -= (runs / events[i].cycle);
            }
            // 범위 넘어가면 확산 x
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                events[i].alive = 0;
                continue;
            }
            // 장애물,탈출구,시간의 벽을 만나면 확산 x
            if (spaceMap[nx][ny] != 0)
            {
                events[i].alive = 0;
                continue;
            }

            int idx = spaceMapCellId[nx][ny];
            dist[idx] = INF;
        }

        /*
        이번 턴에 도달할 수 있는 셀들을 넣는 벡터
        */
        vector<int> nextCells;
        while (!q.empty())
        {
            int idx = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int idy = graph[idx][j];
                // 이동가능한 셀이 없다!
                if (idy == -1)
                {
                    continue;
                }
                // 최소 턴의 수
                if (dist[idy] != -1)
                {
                    continue;
                }
                dist[idy] = runs;
                nextCells.push_back(idy);
            }
        }

        if (nextCells.size() == 0)
        {
            break;
        }
        for (int i : nextCells)
        {
            q.push(i);
        }
        if (dist[cellEnd] != -1)
        {
            break;
        }
        runs++;
    }
    cout << dist[cellEnd] << endl;
}