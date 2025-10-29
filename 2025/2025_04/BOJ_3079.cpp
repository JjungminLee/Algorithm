#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    long long left = 0;

    long long right = m * v[0];

    while (left <= right)
    {
        long long cnt = 0;

        long long mid = (left + right) / 2;

        for (int i = 0; i < v.size(); i++)
        {
            cnt += (mid / v[i]);
        }
        // cout << "mid " << mid << "cnt " << cnt << "left" << left << "right" << right << endl;

        if (cnt >= m)
        {
            right = mid - 1;
        }
        else if (cnt < m)
        {
            left = mid + 1;
        }
    }
    cout << left << endl;
}