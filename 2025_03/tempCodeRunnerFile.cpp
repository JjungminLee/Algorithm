#include <bits/stdc++.h>
using namespace std;
int N, r, c;
int cnt = 0;
int ans;
bool found = false;
void divideFunc(int startX, int startY, int n)
{
    if (found)
        return;
    if (n == 1)
    {

        if (startX == r && startY == c)
        {
            ans = cnt;
            found = true;
            return;
        }
        cnt++;
        return;
    }
    int half = n / 2;
    divideFunc(startX, startY, half);
    divideFunc(startX, startY + half, half);
    divideFunc(startX + half, startY, half);
    divideFunc(startX + half, startY + half, half);
}
int main()
{
    cin >> N >> r >> c;
    int size = 1 << N;
    divideFunc(0, 0, size);
    cout << ans << endl;
}