#include <bits/stdc++.h>
using namespace std;
int n, m;
int parent[500001];
int finds(int num)
{
    if (parent[num] == num)
    {
        return num;
    }
    return parent[num] = finds(parent[num]);
}
void unions(int a, int b)
{
    a = finds(a);
    b = finds(b);
    if (a > b)
    {
        parent[a] = b;
    }
    else
    {
        parent[b] = a;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int cnt = 0;
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt++;

        if (i > 0 && finds(parent[a]) == finds(parent[b]))
        {
            flag = true;
            break;
        }
        unions(a, b);
    }
    if (flag)
    {
        cout << cnt << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}