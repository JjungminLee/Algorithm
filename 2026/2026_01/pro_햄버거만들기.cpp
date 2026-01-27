#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;
    // 1->2->3->1
    vector<int> stk;

    for (int num : ingredient)
    {
        stk.push_back(num);
        if (stk.size() >= 4)
        {
            int n = stk.size();
            if (stk[n - 4] == 1 && stk[n - 3] == 2 && stk[n - 2] == 3 && stk[n - 1] == 1)
            {
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                stk.pop_back();
                answer++;
            }
        }
    }

    return answer;
}