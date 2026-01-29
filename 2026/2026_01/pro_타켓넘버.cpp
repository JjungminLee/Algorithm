#include <bits/stdc++.h>

using namespace std;
int answer = 0;
void dfs(int idx, int cnt, vector<int> numbers, int target)
{
    if (idx == numbers.size())
    {
        if (cnt == target)
        {
            answer++;
        }
        return;
    }
    int curNum = numbers[idx];
    dfs(idx + 1, cnt + curNum, numbers, target);
    dfs(idx + 1, cnt - curNum, numbers, target);
}

int solution(vector<int> numbers, int target)
{
    dfs(0, 0, numbers, target);
    return answer;
}