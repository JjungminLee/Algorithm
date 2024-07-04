#include <bits/stdc++.h>
using namespace std;
int n;
int ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int arr[26] = {
            false,
        };
        string input;
        cin >> input;
        int flag = 1;
        for (int j = 0; j < input.size(); j++)
        {
            if (arr[int(input[j]) - 97])
            {
                if (j >= 1)
                {
                    if (input[j] != input[j - 1])
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            else
            {
                arr[int(input[j]) - 97] = true;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    cout << ans << endl;
}