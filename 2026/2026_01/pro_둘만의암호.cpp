#include <bits/stdc++.h>

using namespace std;
set<char> st;

string solution(string s, string skip, int index)
{
    string answer = "";
    for (char ch : skip)
    {
        st.insert(ch);
    }

    for (int i = 0; i < s.size(); i++)
    {
        int idx = 1;
        int cnt = 0;
        char nch = s[i];
        while (1)
        {
            if (cnt == index)
            {
                answer.push_back(nch);
                break;
            }

            int add = ((s[i] - 'a') + idx) % 26;
            nch = char('a' + add);
            auto it = st.find(nch);
            if (it == st.end())
            {
                cnt++;
            }
            idx++;
        }
    }
    return answer;
}