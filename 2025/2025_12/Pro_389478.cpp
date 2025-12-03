#include <bits/stdc++.h>

using namespace std;
int arr[100][100];

int solution(int n, int w, int num)
{
    int answer = 0;
    int h = 0;
    if (n % w == 0)
    {
        h = n / w;
    }
    else
    {
        h = (n / w) + 1;
    }

    bool toggle = 0; // 0이면 왼쪽부터 1이면 오른쪽부터
    int tmp = 1;
    for (int i = h - 1; i >= 0; i--)
    {
        if (toggle == 0)
        {
            for (int j = 0; j < w; j++)
            {
                arr[i][j] = tmp;
                tmp++;
            }
            toggle = 1;
        }
        else
        {
            for (int j = w - 1; j >= 0; j--)
            {
                arr[i][j] = tmp;
                tmp++;
            }
            toggle = 0;
        }
    }

    int cx = 0;
    int cy = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (arr[i][j] > n)
            {
                arr[i][j] = 0;
            }
            if (arr[i][j] == num)
            {
                cx = i;
                cy = j;
            }
        }
    }
    for (int i = cx; i >= 0; i--)
    {
        if (arr[i][cy] != 0)
        {
            answer++;
        }
    }
    return answer;
}