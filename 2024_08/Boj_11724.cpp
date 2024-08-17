#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1001];

int finds(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    return parent[a] = finds(parent[a]);
}

void unions(int a, int b)
{
    int x = finds(a);
    int y = finds(b);
    if (x < y)
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}
int main()
{
    for (int i = 0; i < 1001; i++)
    {
        parent[i] = i;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        unions(a, b);
    }

    unordered_set<int> set;
    for (int i = 1; i <= n; i++)
    {
        set.insert(finds(i));
    }

    cout << set.size() << endl;
}