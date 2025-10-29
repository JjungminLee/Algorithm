#include <bits/stdc++.h>

using namespace std;
int answer = 0;
bool isMatch(vector<int> v, vector<int> q, int ans)
{
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        auto it = find(q.begin(), q.end(), v[i]);
        if (it != q.end())
        {
            cnt++;
        }
    }
    if (cnt == ans)
    {
        return true;
    }
    return false;
}

void backTracking(int cur, vector<int> v, vector<vector<int>> q, vector<int> ans, int n)
{
    if (v.size() == 5)
    {
        bool flag = true;
        for (int i = 0; i < q.size(); i++)
        {
            if (!isMatch(v, q[i], ans[i]))
            {
                flag = false;
            }
        }
        if (flag)
        {
            answer++;
        }
        return;
    }

    for (int i = cur + 1; i <= n; i++)
    {
        v.push_back(i);
        backTracking(i, v, q, ans, n);
        v.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans)
{

    vector<int> v;
    for (int i = 1; i <= n - 4; i++)
    {
        v.push_back(i);
        backTracking(i, v, q, ans, n);
        v.pop_back(); // 빠뜨리면 안된다!
    }

    return answer;
}