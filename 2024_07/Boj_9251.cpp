#include <bits/stdc++.h>
using namespace std;
string a;
string b;
int lcs[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    cin >> b;
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    cout << lcs[a.length()][b.length()] << endl;
}