#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &key)
{
    int m = key.size();
    vector<vector<int>> rotated(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (key[i][j] == 1)
            {
                rotated[j][m - i - 1] = 1;
            }
        }
    }
    return rotated;
}

bool canUnLock(vector<vector<int>> &key, vector<vector<int>> &extendLock, int x, int y, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            extendLock[x + i][y + j] += key[i][j];
        }
    }
    int n = extendLock.size() - 2 * (m - 1); // n+2*(m-1)

    for (int i = m - 1; i < m - 1 + n; i++)
    {
        for (int j = m - 1; j < m - 1 + n; j++)
        {
            if (extendLock[i][j] != 1)
            {
                return false;
            }
        }
    }
    return true;
}

void restoreLock(vector<vector<int>> &key, vector<vector<int>> &extendLock, int x, int y, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            extendLock[x + i][y + j] -= key[i][j];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    int m = key.size();
    int n = lock.size();

    int extendSize = n + 2 * (m - 1);
    vector<vector<int>> extendLock(extendSize, vector<int>(extendSize, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // m이 추가된거 제외하고 배치
            extendLock[m - 1 + i][m - 1 + j] = lock[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int x = 0; x <= extendSize - m; x++)
        {
            for (int y = 0; y <= extendSize - m; y++)
            {
                if (canUnLock(key, extendLock, x, y, m))
                {
                    return true;
                }
                restoreLock(key, extendLock, x, y, m);
            }
        }
        key = rotate(key);
    }

    return false;
}