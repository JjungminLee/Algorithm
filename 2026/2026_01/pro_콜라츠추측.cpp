#include <bits/stdc++.h>

using namespace std;
int answer = 0;

void dfs(long long num, int cnt)
{

    if (cnt >= 500)
    {
        answer = -1;
        return;
    }
    if (num == 1)
    {
        answer = cnt;
        return;
    }

    if (num % 2 == 0)
    {
        dfs(num / 2, cnt + 1);
    }
    else
    {
        dfs((num * 3) + 1, cnt + 1);
    }
}

int solution(int num)
{
    if (num == 1)
    {
        return 0;
    }
    dfs(num, 0);
    return answer;
}