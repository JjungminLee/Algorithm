#include <bits/stdc++.h>
using namespace std;
int ans;
int n;
vector<pair<int, int>> v;
void backTracking(int depth, int cnt)
{
    if (depth == n)
    {
        ans = max(ans, cnt);
        return;
    }
    if (v[depth].first <= 0)
    {
        backTracking(depth + 1, cnt);
        return;
    }
    bool hit = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first <= 0 || i == depth)
        {
            continue;
        }
        v[depth].first -= v[i].second;
        v[i].first -= v[depth].second;
        hit = true;
        backTracking(depth + 1, cnt + (v[depth].first <= 0) + (v[i].first <= 0));
        v[depth].first += v[i].second;
        v[i].first += v[depth].second;
    }
    if (!hit)
    {
        backTracking(depth + 1, cnt);
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    backTracking(0, 0);
    cout << ans << endl;
}