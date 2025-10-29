#include <bits/stdc++.h>
using namespace std;
int k, w, h;
int arr[201][201];
// x,y번 까지 능력을 z번 사용해서 왔다b
bool visited[201][201][31];
int horseX[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
int horseY[8] = {-2, 2, -1, 1, -2, 2, -1, 1};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/*

1. visited 배열을 중복방문으로만 사용한것!
같은 정점이더라도 말의 능력을 사용해서 왔을때랑 원숭이의 능력을 사용해서 왔을때가 다름! 그래서 다시 방문해도됨(사실상 재방문이 아닌거지)

2. 말 다 가고 원숭이 가는 방법을 사용한것!
이러면 최단경로가 안나올 수 있음

3.전체 이동횟수랑 말 능력 사용횟수를 분류해주지 않은것!
2번 방법을 사용하려면 즉, 말이랑 원숭이 섞어쓰려면 사용횟수 나눠서 따로 큐에 저장해야함!

*/

void horseBfs(int x, int y, int cnt, int cap)
{

    // x,y,이동횟수,능력사용횟수
    queue<tuple<int, int, int, int>> q;
    q.push({x, y, cnt, cap});
    visited[x][y][cap] = true;

    while (!q.empty())
    {
        int x2 = get<0>(q.front());
        int y2 = get<1>(q.front());
        int cnt2 = get<2>(q.front());
        int cap2 = get<3>(q.front());
        q.pop();

        if (x2 == h - 1 && y2 == w - 1)
        {
            cout << cnt2 << endl;
            return;
        }
        if (cap2 < k)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x2 + horseX[i];
                int ny = y2 + horseY[i];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w)
                {
                    if (!visited[nx][ny][cap2 + 1] && arr[nx][ny] == 0)
                    {
                        visited[nx][ny][cap2 + 1] = true;
                        q.push({nx, ny, cnt2 + 1, cap2 + 1});
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x2 + dx[i];
            int ny = y2 + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w)
            {
                if (!visited[nx][ny][cap2] && arr[nx][ny] == 0)
                {
                    // cap2+1안하게 주의!
                    visited[nx][ny][cap2] = true;
                    q.push({nx, ny, cnt2 + 1, cap2});
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{

    cin >> k;
    cin >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> arr[i][j];
        }
    }

    horseBfs(0, 0, 0, 0);
}