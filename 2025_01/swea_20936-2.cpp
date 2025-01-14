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
            while (now != v[now])
            {

                int temp = v[now];
                v[now] = now;
                now = temp;
                ans.push_back(now);
            }
            cout << "i " << i << endl;
            ans.push_back(n + 1);
        }

        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}