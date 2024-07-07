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
    // left
    if (idx == 0)
    {
        for (int i = 0; i < n; i++)
        {
            int pos = 0;
            for (int j = 1; j < n; j++)
            {
                if (arr[i][j] == 0)
                {
                    continue;
                }
                int curr = arr[i][j];
                arr[i][j] = 0;
                if (arr[i][pos] == 0)
                {
                    // 0일때는 합쳐지지 않으니까 pos변화 없음
                    arr[i][pos] = curr;
                }
                else if (arr[i][pos] == curr)
                {
                    arr[i][pos] *= 2;
                    pos++;
                }
                else
                {
                    pos++;
                    // 다르다면 pos를 증가시켰기에 사실상 arr[i][j]위치에 curr이 들어감
                    arr[i][pos] = curr;
                }
            }
        }
    }
    // right
    else if (idx == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int pos = n - 1;
            for (int j = n - 2; j >= 0; j--)
            {
                if (arr[i][j] == 0)
                {
                    continue;
                }
                int curr = arr[i][j];
                arr[i][j] = 0;
                if (arr[i][pos] == 0)
                {
                    // 0일때는 합쳐지지 않으니까 pos변화 없음
                    arr[i][pos] = curr;
                }
                else if (arr[i][pos] == curr)
                {
                    arr[i][pos] *= 2;
                    pos--;
                }
                else
                {
                    pos--;
                    // 다르다면 pos를 증가시켰기에 사실상 arr[i][j]위치에 curr이 들어감
                    arr[i][pos] = curr;
                }
            }
        }
    }
    // up
    else if (idx == 2)
    {
        for (int i = 1; i < n; i++)
        {
            int pos = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 0)
                {
                    continue;
                }
                int curr = arr[i][j];
                arr[i][j] = 0;
                if (arr[pos][i] == 0)
                {
                    // 0일때는 합쳐지지 않으니까 pos변화 없음
                    arr[pos][i] = curr;
                }
                else if (arr[pos][i] == curr)
                {
                    arr[pos][i] *= 2;
                    pos++;
                }
                else
                {
                    pos++;
                    // 다르다면 pos를 증가시켰기에 사실상 arr[i][j]위치에 curr이 들어감
                    arr[pos][i] = curr;
                }
            }
        }
    }
    // down
    else if (idx == 3)
    {
        for (int i = n - 2; i >= 0; i--)
        {
            int pos = n - 1;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 0)
                {
                    continue;
                }
                int curr = arr[i][j];
                arr[i][j] = 0;
                if (arr[pos][i] == 0)
                {
                    // 0일때는 합쳐지지 않으니까 pos변화 없음
                    arr[pos][i] = curr;
                }
                else if (arr[pos][i] == curr)
                {
                    arr[pos][i] *= 2;
                    pos--;
                }
                else
                {
                    pos--;
                    // 다르다면 pos를 증가시켰기에 사실상 arr[i][j]위치에 curr이 들어감
                    arr[pos][i] = curr;
                }
            }
        }
    }
}

void backTracking(int cnt)
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
    int temp[20][20];
    for (int i = 0; i < 4; i++)
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    ans = 0;
    backTracking(0);
    cout << ans << endl;
    return 0;
}
