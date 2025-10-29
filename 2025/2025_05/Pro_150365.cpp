#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'d', 'l', 'r', 'u'};
bool found = false;
string answer = "";
void dfs(int n, int m, int x, int y, int r, int c, int k, string path)
{
    if (found)
    {
        return;
    }
    int dist = abs(x - r) + abs(y - c);
    int remain = k - path.size();
    // 남은 거리가 이동해야하는 거리보다 크면 리턴
    if (dist > remain)
    {
        return;
    }
    // 왔다 갔다 이동할수 있어야하기에 짝수번 이동이 가능해야 ==> "같은 격자를 두 번 이상 방문해도 됩니다.""
    if ((remain - dist) % 2 != 0)
        return;

    if (x == r && y == c && path.size() == k)
    {
        answer = path;
        found = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m)
        {
            dfs(n, m, nx, ny, r, c, k, path + dir[i]);
            if (found)
            {
                return;
            }
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    dfs(n, m, x, y, r, c, k, "");
    if (answer == "")
        return "impossible";
    return answer;
}