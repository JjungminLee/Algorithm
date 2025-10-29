#include <bits/stdc++.h>
using namespace std;

string t;
string p;

vector<int> getpi(string p)
{
    int j = 0;
    vector<int> pi(int(p.size()));
    for (int i = 1; i < p.size(); i++)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (p[i] == p[j])
        {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

vector<int> kmp(string t, string p)
{
    vector<int> ans;
    vector<int> pi = getpi(p);
    int j = 0;
    for (int i = 0; i < t.size(); i++)
    {
        while (j > 0 && t[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (t[i] == p[j])
        {
            // 패턴 길이만큼 다 돌았을떄
            if (j == p.size() - 1)
            {
                ans.push_back(i - p.size() + 1);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    getline(cin, t);
    getline(cin, p);
    vector<int> ans = kmp(t, p);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}