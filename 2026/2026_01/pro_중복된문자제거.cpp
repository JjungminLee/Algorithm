#include <bits/stdc++.h>
using namespace std;

string solution(string my_string)
{
    string answer = "";
    set<char> st;
    map<char, bool> mp;
    for (int i = 0; i < my_string.size(); i++)
    {
        st.insert(my_string[i]);
    }
    vector<pair<char, bool>> v;
    for (char ch : st)
    {
        mp[ch] = false;
    }

    for (int i = 0; i < my_string.size(); i++)
    {
        if (!mp[my_string[i]])
        {
            answer += my_string[i];
            mp[my_string[i]] = true;
        }
    }
    return answer;
}