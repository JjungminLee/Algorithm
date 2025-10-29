#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<char> v;
unordered_map<char, int> mp;
int main()
{
    cin >> n >> k;
    v.assign(n, '?');
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        int num;
        char ch;
        cin >> num >> ch;
        // 시계 반대방향으로
        idx = (idx - num) % n;
        if (idx < 0)
        {
            idx += n;
        }
        if (v[idx] != '?' && v[idx] != ch)
        {
            cout << "!" << endl;
            return 0;
        }
        if (mp.count(ch) && v[idx] != ch)
        {
            cout << "!" << endl;
            return 0;
        }
        v[idx] = ch;
        mp[ch] = 1;
    }

    // 출력은 시계방향으로
    for (int i = 0; i < n; i++)
    {
        cout << v[(idx + i) % n];
    }
    cout << endl;
}