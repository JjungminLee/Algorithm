#include <bits/stdc++.h>

using namespace std;

int solution(int hp)
{
    int answer = 0;
    while (1)
    {
        if (hp == 0)
            break;
        if (hp - 5 >= 0)
        {
            hp -= 5;
            answer++;
        }
        else if (hp - 3 >= 0)
        {
            hp -= 3;
            answer++;
        }
        else if (hp - 1 >= 0)
        {
            hp -= 1;
            answer++;
        }
    }
    return answer;
}