#include <bits/stdc++.h>
using namespace std;
int n;
int arr[16][16];
int ans;

bool isSafe(int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][y] == 1)
        {
            return false;
        }
    }
    // 오른쪽 위
    for (int i = 1; x - i >= 0 && y - i >= 0; i++)
    {
        if (arr[x - i][y - i] == 1)
        {
            return false;
        }
    }
    for (int i = 1; x - i >= 0 && y + i < n; i++)
    {
        if (arr[x - i][y + i] == 1)
        {
            return false;
        }
    }
    return true;
}
void backTracking(int k, int x)
{
    if (k == n)
    {
        ans++;
        return;
    }
    for (int y = 0; y < n; y++)
    {
        if (isSafe(x, y))
        {
            arr[x][y] = 1;
            backTracking(k + 1, x + 1);
            arr[x][y] = 0;
        }
    }
}
int main()
{
    cin >> n;
    backTracking(0, 0);
    cout << ans << endl;
}