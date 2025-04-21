#include <bits/stdc++.h>
using namespace std;
string s;
string t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    cin >> t;

    while (s.size() < t.size())
    {

        if (t.back() == 'A')
        {
            t.pop_back();
        }
        else
        {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if (s == t)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}