#include <bits/stdc++.h>
using namespace std;
int n, s;
vector<int> v;
int minLen = 1e9;
int lefts;
int rights;
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    lefts = 0;
    rights = 0; // 투포인터는 rights가0
    int sum = 0;
    // 구간, 부분합 => 투포인터
    while (rights < n)
    {
        sum += v[rights];
        while (sum >= s)
        {
            minLen = min(rights - lefts + 1, minLen);
            sum -= v[lefts];
            lefts++;
        }
        rights++;
    }
    if (minLen == 1e9)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << minLen << endl;
    }
}