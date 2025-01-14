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
        vector<int> v(n + 2);
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            v[a] = i;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == i)
                continue;
            int now = i;
            do
            {
                int temp = v[now];
                v[now] = now;
                now = temp;
                ans.push_back(now);
            } while (now != v[now]);
            ans.push_back(n + 1);
        }

        cout << ans.size() << "\n";
        for (auto item : ans)
        {
            cout << item << " ";
        }
        cout << "\n";
    }
}