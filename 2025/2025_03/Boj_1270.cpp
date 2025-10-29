
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        unordered_map<long long, long long> mp;
        for (int j = 0; j < num; j++)
        {
            long long k;
            cin >> k;
            mp[k]++;
        }
        long long half = num / 2;
        bool flag = false;
        long long ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            long long key = it->first;
            long long val = it->second;

            if (val > half)
            {
                flag = true;
                ans = key;
                break;
            }
        }
        if (!flag)
        {
            cout << "SYJKGW" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}