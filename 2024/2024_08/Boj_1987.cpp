#include <bits/stdc++.h>
using namespace std;
int r, c;
char arr[21][21];
int ans = INT_MIN;
bool visited[21][21];
bool alpha[26];
int dx[4] = {
    -1,
    1,
    0,
    0,
};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt)
{
    ans = max(ans, cnt);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c)
        {
            int idx = arr[nx][ny] - 65;
            if (!visited[nx][ny] && !alpha[idx])
            {
                visited[nx][ny] = true;
                alpha[idx] = true;
                dfs(nx, ny, cnt + 1);
                visited[nx][ny] = false;
                alpha[idx] = false;
            }
        }
    }
}
int main()
{

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = input[j];
        }
    }
    visited[0][0] = true;
    int idx = arr[0][0] - 65;
    alpha[idx] = true;
    dfs(0, 0, 1);

    cout << ans << endl;
}