#include <bits/stdc++.h>

using namespace std;

int solution(string A, string B)
{
    int answer = 0;
    int curTime = 0;
    while (A != B)
    {
        // 오른쪽으로 밀기
        string tempA = A;
        int size = tempA.size();

        if (curTime > size)
        {
            answer = -1;
            break;
        }

        for (int i = 0; i < A.size(); i++)
        {
            int nextIdx = (i + 1) % size;
            tempA[nextIdx] = A[i];
        }
        A = tempA;
        answer++;
        curTime++;
    }
    return answer;
}