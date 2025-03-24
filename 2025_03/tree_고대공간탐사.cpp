#include <bits/stdc++.h>
using namespace std;
int k, m;
vector<int> tressure;
int arr[5][5];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int arrs[5][5])
{
    bool visited[5][5] = {
        false,
    };
    queue<pair<int, int>> q;
    q.push_back({0, 0});
    visited[0][0] = true;
    set<pair<int, int>> st;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            {
                if (arrs[nx][ny] == arrs[x][y])
                {
                    st.insert({nx, ny});
                }
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push_back({nx, ny});
                }
            }
        }
    }
    return st.size();
}

int main()
{
    // Please write your code here.
    cin >> k >> m;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        tressure.push_back(num);
    }
    int ans = 0;

    while (k--)
    {
        int rotX = 0;
        int rotY = 0;
        int dir = 0;
        int disapears = 0;
        int bfsAns = 0;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {

                // 복사
                int arr90[5][5];
                for (int k = 0; k < 5; k++)
                {
                    for (int r = 0; r < 5; r++)
                    {
                        arr90[k][r] = arr[k][r];
                    }
                }
                for (int k = 1; k <= 3; k++)
                {
                    // 1열이 1행
                    arr90[k][1] = arr[1][k];
                    arr90[k][2] = arr[2][k];
                    arr90[k][3] = arr[3][k];
                }
                // 삭제 횟수
                bfsAns = bfs(arr90);
                if (disapears < bfsAns)
                {
                    rotX = i;
                    rotY = j;
                    dir = 0;
                    disapears = bfsAns;
                }

                int arr180[5][5];
                for (int k = 0; k < 5; k++)
                {
                    for (int r = 0; r < 5; r++)
                    {
                        arr180[k][r] = arr90[k][r];
                    }
                }
                for (int k = 1; k <= 3; k++)
                {
                    // 1열이 1행
                    arr180[k][1] = arr90[1][k];
                    arr180[k][2] = arr90[2][k];
                    arr180[k][3] = arr90[3][k];
                }

                bfsAns = bfs(arr180);
                if (disapears < bfsAns)
                {
                    rotX = i;
                    rotY = j;
                    dir = 0;
                    disapears = bfsAns;
                }

                int arr270[5][5];
                for (int k = 1; k <= 3; k++)
                {
                    // 1열이 1행
                    arr270[k][1] = arr180[1][k];
                    arr270[k][2] = arr180[2][k];
                    arr270[k][3] = arr180[3][k];
                }
                // 삭제 횟수
                bfsAns = bfs(arr270);
                if (disapears < bfsAns)
                {
                    rotX = i;
                    rotY = j;
                    dir = 0;
                    disapears = bfsAns;
                }
            }
        }
    }
    return 0;
}