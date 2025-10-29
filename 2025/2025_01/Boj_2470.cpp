#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
    }
    long long left = 0;
    long long right = n - 1;
    long long start = 0;
    long long end = 0;
    long long minNum = LONG_MAX;
    sort(v.begin(), v.end());
    while (left < right)
    {

        long long sum = v[left] + v[right];

        if (abs(sum) < minNum)
        {
            minNum = abs(sum);
            start = v[left];
            end = v[right];
        }
        if (sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << start << " " << end << endl;
}