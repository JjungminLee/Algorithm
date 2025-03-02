#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int x, y;

void bfs(int h, int w, vector<vector<char>> &arr)
{

    bool visited[110][110] = {
        0,
    };
    int ans = 0;
    map<char, int> mp;
    string str;
    cin >> str;
    if (str != "0")
    {
        for (int k = 0; k < str.size(); k++)
        {
            mp[str[k]]++;
        }
    }
    queue<pair<int, int>> q;
    queue<pair<int, int>> door[26]; // 대기중인 문
    for (int i = 0; i < h; i++)
    {
        if (arr[i][0] != '*')
        {
            visited[i][0] = true;
            q.push({i, 0});
        }
        if (arr[i][w - 1] != '*')
        {
            visited[i][w - 1] = true;
            q.push({i, w - 1});
        }
    }
    for (int i = 0; i < w; i++)
    {
        if (arr[0][i] != '*')
        {
            visited[0][i] = true;
            q.push({0, i});
        }
        if (arr[h - 1][i] != '*')
        {
            visited[h - 1][i] = true;
            q.push({h - 1, i});
        }
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w)
            {
                if (!visited[nx][ny])
                {
                    if (arr[nx][ny] == '.')
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                    else if (islower(arr[nx][ny]))
                    {
                        char ch = arr[nx][ny];
                        mp[ch]++;
                        arr[nx][ny] = '.';
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                        // 열쇠를 만나기 전에 지나쳤던 문들 다 열어주기
                        while (!door[ch - 'a'].empty())
                        {
                            int nnx = door[ch - 'a'].front().first;
                            int nny = door[ch - 'a'].front().second;
                            door[ch - 'a'].pop();

                            q.push({nnx, nny});
                        }
                    }
                    else if (isupper(arr[nx][ny]))
                    {
                        char ch = tolower(arr[nx][ny]);
                        if (mp[ch] > 0)
                        {
                            arr[nx][ny] = '.';
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                        else
                        {
                            door[ch - 'a'].push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                    else if (arr[nx][ny] == '$')
                    {
                        ans++;
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    v.push_back(ans);
}
int main()
{

    cin >> n;
    while (n--)
    {

        cin >> x >> y;
        vector<vector<char>> arr(x + 2, vector<char>(y + 2));
        for (int i = 0; i < x; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < y; j++)
            {
                arr[i + 1][j + 1] = str[j];
            }
        }
        bfs(x + 2, y + 2, arr);
    }
    for (int i : v)
    {
        cout << i << endl;
    }
}