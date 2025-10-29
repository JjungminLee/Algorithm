#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        unordered_map<char, int> mp;
        bool flag = true;
        for (int j = 0; j < str.size(); j++)
        {
            char c = str[j];
            mp[c]++;
            if (mp[c] % 3 == 0)
            {

                if (str[j + 1] != c)
                {

                    flag = false;
                    break;
                }
                j++;
            }
        }
        if (!flag)
        {
            cout << "FAKE" << endl;
        }
        else
        {
            cout << "OK" << endl;
        }
    }
}