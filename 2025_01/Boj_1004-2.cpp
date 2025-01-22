#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int main()
{
    cin >> t;
    while (t--)
    {
        int ans = 0;
        int startx, starty, endx, endy;
        cin >> startx >> starty >> endx >> endy;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            int distStart = (startx - cx) * (startx - cx) + (starty - cy) * (starty - cy);
            int distEnd = (endx - cx) * (endx - cx) + (endy - cy) * (endy - cy);
            int rad = r * r;
            if ((distStart <= rad && distEnd > rad) || (distStart > rad && distEnd <= rad))
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}