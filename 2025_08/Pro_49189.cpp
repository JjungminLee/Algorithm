#include <bits/stdc++.h>

using namespace std;
bool visited[20001];
vector<int> arr[20001];
int maxDepth = 0;
int cntArr[20001];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        cntArr[cur] = cnt;
        q.pop();
        for (int next : arr[cur])
        {
            if (!visited[next])
            {
                q.push({next, cnt + 1});
                visited[next] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bfs();
    for (int i = 1; i <= n; i++)
    {
        if (maxDepth < cntArr[i])
        {
            maxDepth = cntArr[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (cntArr[i] == maxDepth)
        {
            answer++;
        }
    }

    cout << endl;

    return answer;
}