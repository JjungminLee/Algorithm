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

    // 현재 행과 이전행만 유지하면서 슬라이딩 윈도우 기법으로 풀어야함!
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
    int minAns = INT_MAX;
    int maxAns = INT_MIN;

    // 마지막에 cur과 prev자리가 바뀌었기에 실제로 cur를 구하고 싶으면 prev로 접근해야함!
    for (int j = 0; j < 3; j++)
    {
        if (minAns > minDP[prev][j])
        {
            minAns = minDP[prev][j];
        }

        if (maxAns < maxDP[prev][j])
        {
            maxAns = maxDP[prev][j];
        }
    }

    cout << maxAns << " " << minAns << endl;
}