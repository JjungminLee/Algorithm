#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int main()
{
    cin >> n;
    while (1)
    {
        if (n == 0)
        {
            cout << ans << endl;
            break;
        }
        else if ((n - 5) % 5 == 0 || (n - 5) % 3 == 0)
        {
            n -= 5;
            ans++;
        }
        else if ((n - 3) % 5 == 0 || (n - 3) % 3 == 0)
        {
            n -= 3;
            ans++;
        }
        else
        {
            ans = -1;
            cout << ans << endl;
            break;
        }
    }
}