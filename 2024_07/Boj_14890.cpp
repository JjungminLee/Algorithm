#include <bits/stdc++.h>
using namespace std;
int n;
int l;
int rowArr[101][101];
int colArr[101][101];
int ans = 0;

void computation(int arr[101][101])
{
    for (int i = 0; i < n; i++)
    {
        int possible = 1;
        int visited[101] = {
            0,
        };
        for (int j = 0; j < n - 1; j++)
        {

            if (abs(arr[i][j] - arr[i][j + 1]) > 1)
            {
                possible = 0;
                break;
            }
            // 위 ->아래  arr[i][j + 1] 여기가 경사로를 놓는 지점이 됨
            if (arr[i][j] == arr[i][j + 1] + 1)
            {
                for (int k = j + 2; k < j + l + 1; k++)
                {
                    if (k >= n || arr[i][k] != arr[i][j + 1])
                    {
                        possible = 0;
                        break;
                    }
                }
                if (possible)
                {
                    visited[j + l] = true;
                }
                else
                {
                    break;
                }
            }
            // 아래->위 arr[i][j] 여기가 경사로를 놓는 지점이 됨
            if (arr[i][j] == arr[i][j + 1] - 1)
            {
                for (int k = j; k > j - l; k--)
                {
                    if (k < 0 || arr[i][k] != arr[i][j] || visited[k])
                    {
                        possible = 0;
                        break;
                    }
                }
                if (!possible)
                {
                    break;
                }
            }
        }
        if (possible)
        {
            ans++;
        }
    }
}

int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> rowArr[i][j];
            colArr[j][i] = rowArr[i][j];
        }
    }
    computation(rowArr);
    computation(colArr);
    cout << ans << endl;
}
