#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    set<string> st;
    for (string s : phone_book)
    {
        st.insert(s);
    }

    for (string s : phone_book)
    {
        string prefix = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            prefix += s[i];
            if (st.count(prefix))
            {
                return false;
            }
        }
    }
    return true;
}