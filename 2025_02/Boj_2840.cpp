#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<char> v;
unordered_map<char, int> used;

int main()
{
    cin >> n >> k;
    v.assign(n, '?');
    int idx = 0;
    // 채우는건 반시계 출력은 시계
    for (int i = 0; i < k; i++)
    {
        int num;
        char ch;
        cin >> num >> ch;
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
        if (used.count(ch) && v[idx] != ch)
        {
            cout << "!" << endl;
            return 0;
        }
        v[idx] = ch;
        used[ch] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[(idx + i) % n];
    }
    cout << endl;
}
