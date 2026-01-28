#include <bits/stdc++.h>

using namespace std;

void dfs(int num, vector<vector<int>> computers, vector<bool> &visited, int n)
{
    visited[num] = true;
    for (int i = 0; i < n; i++)
    {
        if (computers[num][i] == 1 && !visited[i])
        {
            dfs(i, computers, visited, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            answer++;
            dfs(i, computers, visited, n);
        }
    }
    return answer;
}