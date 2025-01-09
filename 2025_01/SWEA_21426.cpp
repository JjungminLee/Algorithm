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
    // 교집합 존재 x
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
    while (1)
    {
        if (t == 0)
        {
            break;
        }
        Rect white, black1, black2;
        cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
        cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
        cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;

        long long whiteArea = area(white);
        Rect i1 = intersect(white, black1);
        Rect i2 = intersect(white, black2);
        Rect i3 = intersect(i1, i2);
        long long ans = whiteArea - (area(i1) + area(i2) - area(i3));
        if (ans > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        t--;
    }
}