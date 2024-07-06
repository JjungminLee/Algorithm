#include <bits/stdc++.h>
using namespace std;
int n;
int arr[20][20];
// 왼 오 상 하
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans;
void backTracking(int cnt, int idx)
{

    if (cnt == 5)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                ans = max(ans, arr[i][j]);
            }
        }
        return;
    }
    int temp[20][20] = {
        0,
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            int nx = i + dx[idx];
            int ny = j + dy[idx];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                if (arr[i][j] == arr[nx][ny])
                {
                    arr[nx][ny] *= 2;
                    arr[i][j] = 0;
                }
                else if (arr[nx][ny] == 0)
                {
                    arr[nx][ny] = arr[i][j];
                    arr[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        backTracking(cnt + 1, i);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {

        backTracking(1, i);
    }
    cout << ans << endl;
}