#include <bits/stdc++.h>

using namespace std;

int d[11][11];
int c[11];
int r[11];
int solution(vector<vector<int>> beginning, vector<vector<int>> target)
{
    int answer = 0;
    // 차이로 Xor해서 배열 d를 만들고
    // r, c배열로 해당 행,열값을 뒤집어야 하는지 표기
    int n = beginning.size();
    int m = beginning[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d[i][j] = beginning[i][j] ^ target[i][j];
        }
    }

    const int INF = 1e9;

    // 1. r[0]=0 0행 안 뒤집음
    int temp1 = 0;
    bool fail1 = false;
    for (int i = 0; i < n; i++)
        r[i] = 0;
    for (int j = 0; j < m; j++)
        c[j] = 0;
    for (int i = 0; i < m; i++)
    {
        c[i] = d[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        // 전부다 반대 혹은 전부다 같아야함
        bool same = true;
        bool opposite = true;
        for (int j = 0; j < m; j++)
        {
            if (d[i][j] != c[j])
                same = false;
            if (d[i][j] != (c[j] ^ 1))
                opposite = false;
        }
        if (same)
        {
            r[i] = 0;
        }
        else if (opposite)
        {
            r[i] = 1;
        }
        else
        {
            fail1 = true;
        }
    }

    if (fail1)
    {
        temp1 = INF;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (r[i] == 1)
            {
                temp1 += 1;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (c[j] == 1)
            {
                temp1 += 1;
            }
        }
    }

    // 2. r[0]=1 0행 뒤집음
    int temp2 = 0;
    bool fail2 = false;
    for (int i = 0; i < n; i++)
        r[i] = 0;
    for (int j = 0; j < m; j++)
        c[j] = 0;
    r[0] = 1;
    for (int i = 0; i < m; i++)
    {
        c[i] = (1 ^ d[0][i]);
    }
    for (int i = 1; i < n; i++)
    {
        // 전부다 반대 혹은 전부다 같아야함
        bool same = true;
        bool opposite = true;
        for (int j = 0; j < m; j++)
        {
            if (d[i][j] != c[j])
                same = false;
            if (d[i][j] != (c[j] ^ 1))
                opposite = false;
        }
        if (same)
        {
            r[i] = 0;
        }
        else if (opposite)
        {
            r[i] = 1;
        }
        else
        {
            fail2 = true;
        }
    }
    if (fail2)
    {
        temp2 = INF;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (r[i] == 1)
            {
                temp2 += 1;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (c[j] == 1)
            {
                temp2 += 1;
            }
        }
    }

    answer = temp1 < temp2 ? temp1 : temp2;

    return answer == INF ? -1 : answer;
}