#include <bits/stdc++.h>
using namespace std;
int n;
int k;
vector<pair<long long, long long>> arr;
vector<int> bag;
long long ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        long long m;
        long long v;
        cin >> m >> v;

        arr.push_back({m, v});
    }

    for (int i = 0; i < k; i++)
    {
        long long k;
        cin >> k;
        bag.push_back(k);
    }
    // 가방 무게를 오름차순으로 정렬
    sort(bag.begin(), bag.end());
    sort(arr.begin(), arr.end());
    priority_queue<long long> pq;
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && arr[idx].first <= bag[i])
        {
            pq.push(arr[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n";
}