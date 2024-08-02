#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
long long modPow(long long a, long long b, long long c)
{
    if (b == 0)
    {
        return 1;
    }
    if (c == 0)
    {
        return 0;
    }
    long long half = modPow(a, b / 2, c);
    half = (half * half) % c; // 이게 있어야함 중요!
    if (b % 2 == 0)
    {
        return half;
    }
    else
    {
        // 홀수니까 a한번 더 곱해주고 c로 나누기!
        return (half * a) % c;
    }
}
int main()
{
    cin >> a >> b >> c;
    cout << modPow(a, b, c) << endl;
}