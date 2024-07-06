#include <bits/stdc++.h>
using namespace std;
int n;
int arr[20][20];
// 왼 오 상 하
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans;

void moveAndMerge(int idx)
{
    if (idx == 0)
    { // left
        for (int i = 0; i < n; ++i)
        {
            int pos = 0;
            for (int j = 1; j < n; ++j)
            {
                if (arr[i][j] == 0)
                    continue;
                int current = arr[i][j];
                arr[i][j] = 0;
                if (arr[i][pos] == 0)
                {
                    arr[i][pos] = current;
                }
                else if (arr[i][pos] == current)
                {
                    arr[i][pos] *= 2;
                    pos++;
                }
                else
                {
                    pos++;
                    arr[i][pos] = current;
                }
            }
        }
    }
    else if (idx == 1)
    { // right
        for (int i = 0; i < n; ++i)
        {
            int pos = n - 1;
            for (int j = n - 2; j >= 0; --j)
            {
                if (arr[i][j] == 0)
                    continue;
                int current = arr[i][j];
                arr[i][j] = 0;
                if (arr[i][pos] == 0)
                {
                    arr[i][pos] = current;
                }
                else if (arr[i][pos] == current)
                {
                    arr[i][pos] *= 2;
                    pos--;
                }
                else
                {
                    pos--;
                    arr[i][pos] = current;
                }
            }
        }
    }
    else if (idx == 2)
    { // up
        for (int j = 0; j < n; ++j)
        {
            int pos = 0;
            for (int i = 1; i < n; ++i)
            {
                if (arr[i][j] == 0)
                    continue;
                int current = arr[i][j];
                arr[i][j] = 0;
                if (arr[pos][j] == 0)
                {
                    arr[pos][j] = current;
                }
                else if (arr[pos][j] == current)
                {
                    arr[pos][j] *= 2;
                    pos++;
                }
                else
                {
                    pos++;
                    arr[pos][j] = current;
                }
            }
        }
    }
    else if (idx == 3)
    { // down
        for (int j = 0; j < n; ++j)
        {
            int pos = n - 1;
            for (int i = n - 2; i >= 0; --i)
            {
                if (arr[i][j] == 0)
                    continue;
                int current = arr[i][j];
                arr[i][j] = 0;
                if (arr[pos][j] == 0)
                {
                    arr[pos][j] = current;
                }
                else if (arr[pos][j] == current)
                {
                    arr[pos][j] *= 2;
                    pos--;
                }
                else
                {
                    pos--;
                    arr[pos][j] = current;
                }
            }
        }
    }
}

void backTracking(int cnt)
{
    if (cnt == 5)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans = max(ans, arr[i][j]);
            }
        }
        return;
    }

    int temp[20][20];
    for (int i = 0; i < 4; ++i)
    {
        memcpy(temp, arr, sizeof(arr));
        moveAndMerge(i);
        backTracking(cnt + 1);
        memcpy(arr, temp, sizeof(arr));
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> arr[i][j];
        }
    }
    ans = 0;
    backTracking(0);
    cout << ans << endl;
    return 0;
}
