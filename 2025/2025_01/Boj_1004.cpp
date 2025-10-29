#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int main()
{
    cin >> t;
    while (t--)
    {
        int ans = 0;
        int xstart, ystart, xend, yend;
        cin >> xstart >> ystart >> xend >> yend;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            double distStart = (xstart - cx) * (xstart - cx) + (ystart - cy) * (ystart - cy);
            double distEnd = (xend - cx) * (xend - cx) + (yend - cy) * (yend - cy);
            double radius = r * r;
            if ((distStart <= radius && distEnd > radius) || (distStart > radius && distEnd <= radius))
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}