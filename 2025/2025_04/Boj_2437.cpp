#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int target = 1;
    for (int num : v)
    {
        if (num <= target)
        {
            target += num;
        }
        else if (num > target)
        {
            break;
        }
    }
    cout << target << endl;
}