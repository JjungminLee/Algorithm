#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100001];
int ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 1)
        {
            ans++;
        }
        else
        {
            if (pq.empty())
            {
                pq.push(arr[i] - 1);
            }
            else
            {
                int x = pq.top();

                if (x > 1 && x <= arr[i])
                {

                    pq.pop();
                    pq.push(x - 1);
                }
                else if (x == 1)
                {
                    pq.pop();
                    ans++;
                }
            }
        }
    }
    if (!pq.empty())
    {
        ans++;
    }
    cout << ans << endl;
}