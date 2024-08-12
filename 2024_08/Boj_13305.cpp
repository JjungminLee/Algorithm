#include <bits/stdc++.h>
using namespace std;
int n;
long long city[100001];
long long distances[100000];
long long ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> distances[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> city[i];
    }

    long long prev = city[0];
    for (int i = 0; i < n; i++)
    {

        if (city[i] <= prev)
        {
            ans += city[i] * distances[i];
            prev = city[i];
        }
        else
        {
            ans += prev * distances[i];
        }
    }
    cout << ans << endl;
}