#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
int k = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    while (1)
    {
        set<string> st;
        for (int i = 0; i < n; i++)
        {

            string str = v[i].substr(v[i].size() - k);
            st.insert(str);
        }

        if (st.size() == n)
        {
            cout << k << endl;
            break;
        }
        else
        {
            k++;
        }
    }
}