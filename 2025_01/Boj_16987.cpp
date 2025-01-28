#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 0; i < n; i++)
    {
        int left = v[i].first;
        int leftWeight = v[i].second;
        for (int j = i + 1; j < n; j++)
        {
            int right = v[j].first;
            int rightWeight = v[j].first;

            // int brokenLeft = v[i].second-ㄹ
            // dd
        }
    }
}