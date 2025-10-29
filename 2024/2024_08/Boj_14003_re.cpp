#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    cin >> n;
    vector<int> arr(n), dp, parent(n, -1);
    vector<int> lis_index;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        // dp 배열내에 현재 값 위치
        int idx = it - dp.begin();
        if (it == dp.end())
        {
            dp.push_back(arr[i]);
            lis_index.push_back(i);
        }
        else
        {
            // dp 배열 내 위치 갱신
            *it = arr[i];

            lis_index[idx] = i;
        }
        if (idx > 0)
        {
            parent[i] = lis_index[idx - 1];
        }
    }

    int lis_end = lis_index.back();
    vector<int> lis;
    for (int i = lis_end; i != -1; i = parent[i])
    {
        lis.push_back(arr[i]);
    }
    reverse(lis.begin(), lis.end());
    cout << dp.size() << endl;
    for (int num : lis)
    {
        cout << num << " ";
    }
    cout << endl;
}