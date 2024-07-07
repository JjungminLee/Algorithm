#include <bits/stdc++.h>
using namespace std;

int n;
int p[49];
int s[49];
int ans;
bool isOrdered()
{
    for (int i = 0; i < n; i++)
    {
        if (p[i] % 3 != i % 3)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<int> original(p, p + n);
    while (1)
    {
        if (isOrdered())
        {
            break;
        }

        int temp[49] = {
            0,
        };
        for (int i = 0; i < n; i++)
        {
            temp[i] = p[i];
        }
        for (int i = 0; i < n; i++)
        {
            p[s[i]] = temp[i];
        }
        ans++;
        if (original == vector<int>(p, p + n))
        {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}