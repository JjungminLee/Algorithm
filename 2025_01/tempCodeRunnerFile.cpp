#include <bits/stdc++.h>
using namespace std;
int n;
int arr[51][51];
int ans[51];
int main()
{
    cin >> n;
    // a와b가 2-친구
    // arr[a][b]= 1 arr[b][a]=1
    // arr[a][a]=0
    // or
    // arr[a][c]=1 arr[b][c]=1
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {

            if (str[j] == 'N')
            {
                arr[i][j] = 0;
            }
            else if (str[j] == 'Y')
            {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            // i번째와 j번째가 2-친구임을 판단
            if (arr[i][j] == 1)
            {

                ans[i]++;
            }
            else
            {
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    if (arr[i][k] == 1 && arr[k][j] == 1)
                    {

                        ans[i]++;
                        break;
                    }
                }
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    int maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans[i] > maxNum)
        {
            maxNum = ans[i];
        }
    }
    cout << maxNum << endl;
}