#include <bits/stdc++.h>

using namespace std;
int serverCount(int m, int num)
{
    for (int i = 0; i <= 1000; i++)
    {
        if ((i * m) <= num && num < (i + 1) * m)
        {
            return i;
        }
    }
    return 0;
}

int solution(vector<int> players, int m, int k)
{
    int answer = 0; // 증설횟수
    vector<int> servers(players.size());
    for (int i = 0; i < players.size(); i++)
    {
        int num = players[i];
        int serverCnt = serverCount(m, num);
        if (servers[i] <= serverCnt)
        {

            int newServerCnt = serverCnt - servers[i];
            answer += newServerCnt;
            for (int j = i; j < i + k && j < players.size(); j++)
            {
                servers[j] += newServerCnt;
            }
        }
    }

    return answer;
}