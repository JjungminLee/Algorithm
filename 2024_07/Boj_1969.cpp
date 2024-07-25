#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> arr;
int counts[51][51];
string ans;

// i번째, ATGC중, 빈도수
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; i++)
    {
        int counts[4] = {
            0,
        };

        for (int j = 0; j < n; j++)
        {

            if (arr[j][i] == 'A')
            {
                counts[0]++;
            }
            else if (arr[j][i] == 'C')
            {
                counts[1]++;
            }
            else if (arr[j][i] == 'G')
            {
                counts[2]++;
            }
            else if (arr[j][i] == 'T')
            {
                counts[3]++;
            }
        }

        int maxNum = 0;
        int idx = 0;

        for (int k = 0; k < 4; k++)
        {
            if (maxNum < counts[k])
            {
                maxNum = counts[k];
                idx = k;
            }
            else if (maxNum == counts[k])
            {
                if (idx > k)
                {
                    idx = k;
                }
            }
        }

        if (idx == 0)
        {
            ans += 'A';
        }
        else if (idx == 1)
        {
            ans += 'C';
        }
        else if (idx == 2)
        {
            ans += 'G';
        }
        else if (idx == 3)
        {
            ans += 'T';
        }
    }
    int countAns = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != ans[j])
            {
                cnt++;
            }
        }
        countAns += cnt;
    }
    cout << ans << endl;
    cout << countAns << endl;
}