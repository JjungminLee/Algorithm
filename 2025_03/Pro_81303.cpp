#include <bits/stdc++.h>

using namespace std;

string solution(int n, int k, vector<string> cmd)
{
    string answer = "";
    vector<int> prev(n), next(n);
    stack<int> deleted;
    vector<bool> isExist(n, true);
    for (int i = 0; i < n; i++)
    {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;
    int cur = k;
    for (string str : cmd)
    {
        if (str[0] == 'U')
        {
            int num = stoi(str.substr(2));
            while (num--)
            {
                cur = prev[cur];
            }
        }
        else if (str[0] == 'D')
        {
            int num = stoi(str.substr(2));
            while (num--)
            {
                cur = next[cur];
            }
        }
        else if (str[0] == 'C')
        {
            deleted.push(cur);
            isExist[cur] = false;
            if (prev[cur] != -1)
            {
                next[prev[cur]] = next[cur];
            }
            if (next[cur] != -1)
            {
                prev[next[cur]] = prev[cur];
            }
            if (next[cur] != -1)
            {
                cur = next[cur];
            }
            else
            {
                cur = prev[cur];
            }
        }
        else if (str[0] == 'Z')
        {
            int num = deleted.top();
            deleted.pop();
            isExist[num] = true;
            if (prev[num] != -1)
            {
                next[prev[num]] = num;
            }
            if (next[num] != -1)
            {
                prev[next[num]] = num;
            }
        }
    }
    for (int i = 0; i < isExist.size(); i++)
    {
        if (isExist[i])
        {
            answer += "O";
        }
        else
        {
            answer += "X";
        }
    }
    return answer;
}