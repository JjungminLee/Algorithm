#include <bits/stdc++.h>
using namespace std;
int N, r, c;
int cnt = 0;
int ans;
void divideFunc(int startX, int startY, int size)
{
    if (size == 1)
    {
        if (startX == r && startY == c)
        {
            ans = cnt;
        }
        cnt++;
        return;
    }
    int half = size / 2;
    // 1
    if (r < startX + half && c < startY + half)
    {
        divideFunc(startX, startY, half);
    }
    // 2
    else if (r < startX + half && startY + half <= c)
    {
        cnt += half * half;
        divideFunc(startX, startY + half, half);
    }
    // 3
    else if (startX + half <= r & c < startY + half)
    {
        cnt += 2 * half * half;
        divideFunc(startX + half, startY, half);
    }
    // 4
    else if (startX + half <= r && startY + half <= c)
    {
        cnt += 3 * half * half;
        divideFunc(startX + half, startY + half, half);
    }
}
int main()
{
    cin >> N >> r >> c;
    int size = 1 << N;
    divideFunc(0, 0, size);
    cout << ans << endl;
}