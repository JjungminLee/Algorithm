#include <bits/stdc++.h>

using namespace std;

int solution(int chicken)
{
    int answer = -1;
    int coupon = 0;
    while (1)
    {
        // 무한루프 걸리는 이유 생각해보기!
        if (chicken / 10 == 0)
        {
            answer++;
            break;
        }
        answer += (chicken / 10);
        int temp = (chicken / 10) + (chicken % 10);
        chicken = temp;
    }
    return answer;
}