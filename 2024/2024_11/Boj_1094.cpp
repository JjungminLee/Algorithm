#include <bits/stdc++.h>
using namespace std;
int x;
int main()
{
    cin >> x;
    auto s = bitset<7>(x);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
}