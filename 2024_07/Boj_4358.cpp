#include <bits/stdc++.h>
using namespace std;

map<string, double> m;
int cnt = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    while (getline(cin, input))
    {

        cnt++;
        m[input]++;
    }
    map<string, double>::iterator iter;
    cout << fixed;
    cout.precision(4);
    for (iter = m.begin(); iter != m.end(); iter++)
    {

        double num = iter->second / cnt;
        double ans = num * 100;
        cout << iter->first << " " << ans << "\n";
    }
}
