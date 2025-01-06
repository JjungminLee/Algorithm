#include <bits/stdc++.h>
using namespace std;
int arr[5][5];
int arr2[5][5];
int v[5][5];

void color(int num)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == num)
            {
                v[i][j] = 1;
                return;
            }
        }
    }
}

int bingo()
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        int num = 0;
        for (int j = 0; j < 5; j++)
        {
            if (v[i][j] == 1)
            {
                num++;
            }
        }
        if (num == 5)
        {
            cnt++;
        }
    }
    // cout << "cnt1-1 " << cnt << endl;

    for (int i = 0; i < 5; i++)
    {
        int num = 0;
        for (int j = 0; j < 5; j++)
        {
            if (v[j][i] == 1)
            {
                num++;
            }
        }
        if (num == 5)
        {
            cnt++;
        }
    }
    // cout << "cnt1-2 " << cnt << endl;
    // 대각선 체크
    int num = 0;
    for (int i = 0; i < 5; i++)
    {

        if (v[i][i] == 1)
        {
            num++;
        }
    }
    if (num == 5)
    {
        cnt++;
    }
    num = 0;
    for (int i = 0; i < 5; i++)
    {
        if (v[i][4 - i] == 1)
        {
            num++;
        }
    }

    if (num == 5)
    {
        cnt++;
    }

    // cout << "cnt2 " << cnt << endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (cnt >= 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int find = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int n;
            cin >> n;

            arr[i][j] = n;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int num;
            cin >> num;
            arr2[i][j] = num;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (find)
        {
            break;
        }
        for (int j = 0; j < 5; j++)
        {
            int num = arr2[i][j];
            color(num);
            if (find)
            {
                break;
            }

            if (i > 0)
            {
                if (bingo() == 1)
                {

                    int cnt = 5 * i + (j + 1);
                    cout << cnt << endl;
                    find = 1;
                    break;
                }
            }
        }
    }
}