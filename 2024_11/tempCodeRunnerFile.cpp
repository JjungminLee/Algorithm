#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> row;
vector<int> col;
int main()
{
    cin >> n;
    int total = 100 * n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        row.push_back(a);
        col.push_back(b);
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    int x = 10 + row[0] - row[1];
    int y = 10 + col[0] - col[1];

    cout << total - (x * y) << endl;
}