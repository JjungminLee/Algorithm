#include <bits/stdc++.h>
using namespace std;
int p[49];
int s[49];
int n;
int ans = 0;
vector<vector<int>> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    while (1)
    {
        int flag = 0;
        // 0,1,2 순서대로 되는지 확인
        for (int i = 0; i < n; i++)
        {
            if (p[i] % 3 != i % 3)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
        flag = 0;
        // vector에 똑같은게 있으면 stop
        for (int i = 0; i < v.size(); i++)
        {

            for (int j = 0; j < n; j++)
            {
                if (p[j] != v[i][j])
                {
                    flag = 1;
                }
            }
        }
        if (flag == 1)
        {
            ans = -1;

            break;
        }
        vector<int> original(p, p + n);
        int temp[49] = {
            0,
        };

        for (int i = 0; i < n; i++)
        {
            temp[i] = p[i];
        }
        for (int i = 0; i < n; i++)
        {

            p[s[i]] = temp[i];
        }
        ans++;
        if (original == vector<int>(p, p + n))
        {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}