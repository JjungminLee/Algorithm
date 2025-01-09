#include <bits/stdc++.h>
using namespace std;
int t;

struct Rect
{
    long long x1, x2, y1, y2;
};
long long area(Rect &r)
{
    return (r.x2 - r.x1) * (r.y2 - r.y1);
}
Rect intersect(Rect &a, Rect &b)
{
    Rect r;
    r.x1 = max(a.x1, b.x1);
    r.x2 = min(a.x2, b.x2);
    r.y1 = max(a.y1, b.y1);
    r.y2 = min(a.y2, b.y2);
    if (r.x1 >= r.x2 || r.y1 >= r.y2)
    {
        r.x1 = 0;
        r.x2 = 0;
        r.y1 = 0;
        r.y2 = 0;
    }
    return r;
}
int main()
{
    cin >> t;
    while (t--)
    {
        Rect w, b1, b2;
        cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
        cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
        cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
        long long warea = area(w);
        Rect i1 = intersect(w, b1);
        Rect i2 = intersect(w, b2);
        Rect i3 = intersect(i1, i2);
        long long ans = warea - (area(i1) + area(i2) - area(i3));
        if (ans > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}