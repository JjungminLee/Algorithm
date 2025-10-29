#include <bits/stdc++.h>
using namespace std;

string input;
long long n;
long long ans[10];

void calc(int n, int digit)
{
    while (n > 0)
    {
        ans[n % 10] += digit;
        n /= 10;
    }
}

// a++ 해서 일의 자리를 0으로 b--해서 일의자리를 9로
void sol(int A, int B, int digit)
{
    // A의 일의 자리수를 0으로 맞춘다.
    while (A % 10 != 0 && A <= B)
    {
        // 맞추기 전까지 계산
        calc(A, digit);
        A++;
    }
    if (A > B)
    {
        return;
    }

    // B의 일의 자리수를 9로 맞춘다.
    while (B % 10 != 9 && A <= B)
    {
        calc(B, digit);
        B--;
    }
    long long tmp = (B / 10 - A / 10) + 1;
    for (int i = 0; i < 10; i++)
    {
        ans[i] += tmp * digit;
    }
    sol(A / 10, B / 10, digit * 10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    sol(1, n, 1);

    for (int i = 0; i < 10; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
