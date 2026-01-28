#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> answer;
bool found;
bool compares(vector<string> a, vector<string> b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

void dfs(string d, vector<vector<string>> tickets, vector<bool> visited, vector<string> path)
{
    int usedCnt = 0;
    if (found)
        return;
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i])
        {
            usedCnt++;
        }
    }
    if (usedCnt == n)
    {
        answer = path;
        found = true;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            string a = tickets[i][0];
            string b = tickets[i][1];
            if (a == d)
            {
                visited[i] = true;
                path.push_back(b);
                dfs(b, tickets, visited, path);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    n = tickets.size();
    vector<bool> visited(n);
    sort(tickets.begin(), tickets.end(), compares);
    vector<string> path;
    path.push_back("ICN");
    dfs("ICN", tickets, visited, path);

    return answer;
}