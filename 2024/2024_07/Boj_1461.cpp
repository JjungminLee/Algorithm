#include <bits/stdc++.h>
using namespace std;
int n, m;
int stdNum = 0; // 음수,양수 가르는 기준
int maxNum = 0;
vector<int> mv;
vector<int> pv;
vector<int> v;
int ans;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (input < 0)
        {
            mv.push_back(input);
        }
        else
        {
            pv.push_back(input);
        }
    }
    sort(mv.begin(), mv.end());
    sort(pv.begin(), pv.end(), greater<int>());
    for (int i = 0; i < mv.size(); i += m)
    {
        v.push_back(abs(mv[i]));
    }
    for (int i = 0; i < pv.size(); i += m)
    {
        v.push_back(abs(pv[i]));
    }
    sort(v.begin(), v.end(), greater<int>());
    ans += v[0];

    for (int i = 1; i < v.size(); i++)
    {
        ans += 2 * v[i];
    }
    cout << ans << endl;
}