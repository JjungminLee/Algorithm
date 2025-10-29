#include <bits/stdc++.h>
using namespace std;
int n, s;
vector<int> v;
int lefts;
int rights;
int sum;
int ans = 1e9;
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    while (rights < n)
    {
        sum += v[rights];
        while (sum >= s)
        {
            ans = min(ans, rights - lefts + 1);
            sum -= v[lefts];
            lefts++;
        }
        rights++;
    }
    if (ans == 1e9)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}