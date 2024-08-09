#include <bits/stdc++.h>
using namespace std;

int n;
int arr[3];
int minDP[2][3];
int maxDP[2][3];

int main()
{
    cin >> n;
    memset(minDP, INT_MAX, sizeof(minDP));
    memset(maxDP, INT_MIN, sizeof(maxDP));
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        minDP[0][i] = arr[i];
        maxDP[0][i] = arr[i];
    }
    int cur = 1;
    int prev = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[j];
        }
        minDP[cur][0] = min(minDP[prev][0], minDP[prev][1]) + arr[0];
        minDP[cur][1] = min(minDP[prev][0], min(minDP[prev][1], minDP[prev][2])) + arr[1];
        minDP[cur][2] = min(minDP[prev][1], minDP[prev][2]) + arr[2];

        maxDP[cur][0] = max(maxDP[prev][0], maxDP[prev][1]) + arr[0];
        maxDP[cur][1] = max(maxDP[prev][0], max(maxDP[prev][1], maxDP[prev][2])) + arr[1];
        maxDP[cur][2] = max(maxDP[prev][1], maxDP[prev][2]) + arr[2];
        swap(cur, prev);
    }
    int maxAns = INT_MIN;
    int minAns = INT_MAX;
    // cur행을 기준으로 찾아야하는데 반복문 마지막에서 swap해서 prev로 찾아야!
    for (int i = 0; i < 3; i++)
    {
        if (maxAns < maxDP[prev][i])
        {
            maxAns = maxDP[prev][i];
        }
        if (minAns > minDP[prev][i])
        {
            minAns = minDP[prev][i];
        }
    }
    cout << maxAns << " " << minAns << endl;
}