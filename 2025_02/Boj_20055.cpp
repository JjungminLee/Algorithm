#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[2][101];
bool robot[2][101];
int ans;
int checkZero(int n, int k)
{

    int cnt = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (arr[i][j] <= 0)
            {
                cnt++;
            }
        }
    }

    if (cnt >= k)
    {
        return 1;
    }
    return 0;
}
int main()
{ // 0행 0열 ~ 0행 i-2열 까지는 -> 열+1
    // 0행 i-1열은 -> 1행 i-1열로
    // 1행0열은 -> 0행 0열로
    // 1행 i-1열부터 1열은 -> 열-1
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[0][i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[1][n - i - 1];
    }

    while (1)
    {
        ans++;
        int rotArr[2][101];
        bool rotRobot[2][101] = {false};

        /* 벨트 회전*/
        // 0행 0열 ~ 0행 i-2열 까지는 -> 열+1
        // 0행 i-1열은 -> 1행 i-1열로
        // 1행0열은 -> 0행 0열로
        // 1행 i-1열부터 1열은 -> 열-1
        rotArr[1][n - 1] = arr[0][n - 1];
        for (int i = 1; i < n; i++)
        {
            rotArr[0][i] = arr[0][i - 1];
        }
        rotArr[0][0] = arr[1][0];
        for (int i = n - 1; i >= 1; i--)
        {
            rotArr[1][i - 1] = arr[1][i];
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = rotArr[i][j];
            }
        }
        /*로봇 회전*/
        for (int i = 1; i < n; i++)
        {
            rotRobot[0][i] = robot[0][i - 1];
        }
        for (int i = 1; i < n; i++)
        {
            robot[0][i] = rotRobot[0][i];
        }
        robot[0][0] = false;
        robot[0][n - 1] = false;

        /*로봇이동*/

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[0][i + 1] > 0 && !robot[0][i + 1] && robot[0][i])
            {
                robot[0][i + 1] = true;
                robot[0][i] = false;
                arr[0][i + 1]--;
            }
        }
        robot[0][n - 1] = false;

        if (arr[0][0] > 0)
        {
            robot[0][0] = true;
            arr[0][0]--;
        }

        if (checkZero(n, k))
        {
            cout << ans << endl;
            break;
        }
    }
}