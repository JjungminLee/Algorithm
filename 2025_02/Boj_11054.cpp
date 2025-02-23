#include <bits/stdc++.h>
using namespace std;
int n;
int lis[1000];
int arr[1000];
int lds[1000];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        lis[i] = 1;
        lds[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(lis[i] + lds[i], ans);
    }
    cout << ans - 1 << endl;
}