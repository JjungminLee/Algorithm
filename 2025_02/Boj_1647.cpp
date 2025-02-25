#include <bits/stdc++.h>
using namespace std;
int n, m;
int parents[100001];
vector<pair<int, pair<int, int>>> v;
int totalCnt;
int maxCnt;

int getRoot(int num)
{
    if (parents[num] == num)
    {
        return num;
    }
    return parents[num] = getRoot(parents[num]);
}

void unionParent(int a, int b)
{
    int aRoot = getRoot(a);
    int bRoot = getRoot(b);
    if (aRoot < bRoot)
    {
        parents[bRoot] = aRoot;
    }
    else
    {
        parents[aRoot] = bRoot;
    }
}

bool find(int a, int b)
{
    int aRoot = getRoot(a);
    int bRoot = getRoot(b);
    if (parents[aRoot] == parents[bRoot])
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        parents[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        c = v[i].first;
        a = v[i].second.first;
        b = v[i].second.second;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        a = v[i].second.first;
        b = v[i].second.second;
        c = v[i].first;
        if (!find(a, b))
        {
            unionParent(a, b);
            totalCnt += c;
            maxCnt = max(maxCnt, c);
        }
    }

    cout << totalCnt - maxCnt << endl;
}