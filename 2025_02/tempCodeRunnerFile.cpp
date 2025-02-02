#include <bits/stdc++.h>
using namespace std;
int length, width, height;
vector<pair<int, int>> v;
int n;
int sum;
int ans;
void divide(int l, int w, int h)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i].second > 0)
        {
            int num = pow(2, v[i].first);
            int l2 = l - num;
            int w2 = w - num;
            int h2 = h - num;
            v[i].second -= 1;
            if (l2 > 0)
            {
                ans++;
                divide(l2, w, h);
            }
            if (w2 > 0)
            {
                ans++;
                divide(l, w2, h);
            }
            if (h2 > 0)
            {
                ans++;
                divide(l, w, h2);
            }
        }
    }
}
int main()
{
    cin >> length >> width >> height;
    sum = length * width * height;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first > b.first; });

    divide(length, width, height);
    cout << ans << endl;
}