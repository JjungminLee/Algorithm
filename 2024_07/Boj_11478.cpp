#include <bits/stdc++.h>
using namespace std;

string a;
unordered_set<string> maps;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    int n = a.length();
    for (int i = 0; i < n; i++)
    {
        string target = "";
        for (int j = i; j < n; j++)
        {
            target += a[j];
            maps.insert(target);
        }
    }
    cout << maps.size() << endl;
}
