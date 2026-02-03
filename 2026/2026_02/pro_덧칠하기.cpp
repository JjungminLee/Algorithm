#include <bits/stdc++.h>

using namespace std;
bool covers[100005];
int solution(int n, int m, vector<int> section)
{
    int answer = 0;

    for (int i = 0; i < section.size(); i++)
    {
        int num = section[i];
        if (!covers[num])
        {
            answer++;
            for (int j = num; j < num + m; j++)
            {
                if (j <= n)
                {
                    covers[j] = true;
                }
            }
        }
    }
    return answer;
}