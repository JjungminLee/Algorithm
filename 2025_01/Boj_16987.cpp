#include <bits/stdc++.h>
using namespace std;

int n;
// 내구도, 무게
vector<pair<int, int>> v;
int ans;
// 인덱스 , 현재 깬 개수
void backTracking(int depth, int cnt)
{

    if (depth == n)
    {
        ans = max(cnt, ans);
        return;
    }
    // 내구도

    if (v[depth].first <= 0)
    {
        backTracking(depth + 1, cnt);
        return;
    }
    // 한번이라도 계란을 친적이 있는지
    bool hit = false;
    for (int i = 0; i < n; i++)
    {
        // 이미 깨졌거나 자기자신은 치면 안됨
        if (v[i].first <= 0 || i == depth)
        {
            continue;
        }
        v[depth].first -= v[i].second;
        v[i].first -= v[depth].second;
        hit = true;
        // 깨졌을때만 cnt+1이고, 왼쪽,오른쪽이 같이 깨질 수 있음을 고려해야함!
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
        // 내구도 무게
        cin >> a >> b;
        v.push_back({a, b});
    }

    backTracking(0, 0);
    cout << ans << endl;
}