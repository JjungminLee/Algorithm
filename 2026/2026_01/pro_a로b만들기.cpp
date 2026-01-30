#include <bits/stdc++.h>

using namespace std;

int solution(string before, string after)
{
    int answer = 0;
    vector<char> b;
    vector<char> a;
    for (char ch : before)
    {
        b.push_back(ch);
    }
    for (char ch : after)
    {
        a.push_back(ch);
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    for (int i = 0; i < b.size(); i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}