#include <bits/stdc++.h>
using namespace std;
#define INF 987654321;
int n;
int arr[16][16];
int dp[16][1 << 16]; // dp[pos][visited] 현재 pos 위치에 있고, visited 상태일 때 최소 비용

int tsp(int pos, int bit)
{
    // 만약 비트 마스킹이 다 채워지면 0으로 돌아가기
    // n이 4하면 16-1 = 15 1111 이 됨!
    if (bit == (1 << n) - 1)
    {
        // 길이 없다면
        if (arr[pos][0] == 0)
        {
            return INF;
        }
        return arr[pos][0];
    }

    // 이미 있으면 그거 리턴
    if (dp[pos][bit] != -1)
    {
        return dp[pos][bit];
    }

    // min값 찾는거기에 이거 처리하는거 중요!
    dp[pos][bit] = INF;
    // 방문하지 않은 도시들 체크 하면서 방문해보기!
    for (int i = 0; i < n; i++)
    {
        // 길이 없다용!
        if (arr[pos][i] == 0)
        {
            continue;
        }
        // 방문여부 확인
        if ((bit & (1 << i)) == (1 << i))
        {
            continue;
        }
        // 방문하지 않은 곳이라면 방문 한거 추가해야!
        dp[pos][bit] = min(dp[pos][bit], arr[pos][i] + tsp(i, bit | (1 << i)));
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
