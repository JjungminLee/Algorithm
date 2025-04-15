#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while (1)
    {
        if (v.size() == 1)
        {
            break;
        }

        v[0]--;
        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();
        ans++;
        if (v[0] == 0)
        {
            for (int i = 0; i < v.size() - 1; i++)
            {
                v[i] = v[i + 1];
            }
            v.pop_back();
        }
    }
    cout << ans << endl;
}