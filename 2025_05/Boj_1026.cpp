#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;

bool compartors(int a, int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        b.push_back(num);
    }
    int answer = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), compartors);
    for (int i = 0; i < b.size(); i++)
    {
        answer += (a[i] * b[i]);
    }
    cout << answer << endl;
}