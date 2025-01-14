#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            v[a] = i; // v[값]=위치
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == i)
            {
                continue;
            }
            int now = i;
            while (v[now] != now)
            {

                int temp = v[now];
                v[now] = now;
                now = temp;
                ans.push_back(now);
            }
        }

        if (ans.size() == 0)
        {
            cout << ans.size() << endl;
            cout << endl;
        }
        else
        {
            cout << ans.size() << endl;
            for (auto i : ans)
            {
                cout << i << " ";
            }
            cout << n + 1 << endl;
        }
    }
}