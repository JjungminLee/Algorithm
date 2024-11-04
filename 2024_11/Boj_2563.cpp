#include <bits/stdc++.h>
using namespace std;
int n;
bool arr[100][100];
int ans;
int main()
{
    cin >> n;
    int total = 100 * n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < a + 10; i++)
        {
            for (int j = b; j < b + 10; j++)
            {
                if (!arr[i][j])
                {
                    ans++;
                    arr[i][j] = true;
                }
            }
        }
    }
    cout << ans << endl;
}