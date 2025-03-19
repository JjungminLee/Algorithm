#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};
int arr[31][31];

bool isBlock(int x, int y, int m, int n)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m || ny < 0 || ny > n)
        {
            return false;
        }
        if (arr[nx][ny] != arr[x][y])
        {
            return false;
        }
    }
    return true;
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = board[i][j];
        }
    }
    while (1)
    {
        set<pair<int, int>> st;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != '\0')
                {
                    if (isBlock(i, j, m, n))
                    {
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = i + dx[k];
                            int ny = j + dy[k];
                            st.insert({nx, ny});
                        }
                    }
                }
            }
        }
        cout << "st " << st.size() << endl;
        if (st.size() == 0)
        {
            break;
        }

        for (auto it = st.begin(); it != st.end(); it++)
        {
            int x = it->first;
            int y = it->second;
            arr[x][y] = '\0';
            answer++;
        }
        for (int i = m - 1; i >= 0; i--)
        { // 아래-> 위 방향으로 올라가면서 내리기를 해야 다른값으로 복사가 안됨
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] != '\0')
                {
                    int k = i;
                    while (k + 1 < m && arr[k + 1][j] == '\0')
                    { // 최대한 빈칸일때까지 내림
                        k++;
                    }
                    if (k != i)
                    {
                        arr[k][j] = arr[i][j];
                        arr[i][j] = '\0';
                    }
                }
            }
        }
    }
    return answer;
}