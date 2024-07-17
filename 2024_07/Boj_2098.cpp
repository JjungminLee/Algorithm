#include <bits/stdc++.h>
using namespace std;
int intMax = INT_MAX - 1;
#define INF intMax;
int n;
int arr[16][16];
int dp[16][1 << 16];
int tsp(int pos, int bit)
{
    // bit 마스킹 전부다 방문한거면 다시 원점으로 돌아오게
    if (bit == (1 << n) - 1)
    {
        if (arr[pos][0] == 0)
        {
            return INF;
        }
        return arr[pos][0];
    }

    // 이미 dp 값이 있다면 그거 리턴
    if (dp[pos][bit] != -1)
    {
        return dp[pos][bit];
    }

    dp[pos][bit] = INF;
    // 그게 아니면 방문안한 도시 다 방문해보기
    for (int i = 0; i < n; i++)
    {
        if (arr[pos][i] == 0)
        {
            continue;
        }
        if ((bit & (1 << i)) == (1 << i))
        {
            continue;
        }
        dp[pos][bit] = min(dp[pos][bit], arr[pos][i] + tsp(i, bit | 1 << i));
    }
    return dp[pos][bit];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << tsp(0, 1) << endl; // 첫 번째 도시부터 시작하여 방문 상태를 1로 설정 (0001)

    return 0;
}
