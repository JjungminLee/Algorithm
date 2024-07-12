#include <bits/stdc++.h>
using namespace std;
int n, m;
int stdNum = 0; // 음수,양수 가르는 기준
int arr[10000001];
int maxNum = 0;
int mArr[100001];
int pArr[100001];
vector<int> v;
int ans;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            stdNum = i;
            break;
        }
    }
    int midx = 0;

    for (int i = 0; i < stdNum; i += m)
    {
        mArr[midx] = arr[i];
        midx++;
    }

    int pidx = 0;

    for (int i = n - 1; i >= stdNum; i -= m)
    {
        pArr[pidx] = arr[i];
        pidx++;
    }

    // 양수는 내림차순
    sort(pArr, pArr + pidx, greater<int>());
    sort(mArr, mArr + midx);

    // max에 해당하는 인덱스가 lastIdx임
    for (int i = 0; i < midx; i++)
    {

        ans += (2 * abs(mArr[i]));
    }
    for (int i = 0; i < pidx; i++)
    {

        ans += (2 * abs(pArr[i]));
    }

    maxNum = max(abs(mArr[0]), abs(pArr[0]));

    cout << ans - maxNum << endl;
}