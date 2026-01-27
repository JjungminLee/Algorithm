#include <bits/stdc++.h>

using namespace std;

map<string, set<string>> mp;
map<string, set<string>> mp2;
vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    set<string> st;
    for (int i = 0; i < report.size(); i++)
    {
        string s = report[i];
        int start = 0;
        string str1 = "";
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ' ')
            {
                start = j + 1;
                break;
            }
            else
            {
                str1 += s[j];
            }
        }
        string str2 = "";
        for (int j = start; j < s.size(); j++)
        {
            str2 += s[j];
        }

        mp[str2].insert(str1);  // 신고당한
        mp2[str1].insert(str2); // 신고한
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second.size() >= k)
        {
            st.insert(it->first);
        }
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        string key = id_list[i];
        set<string> st2 = mp2[key];
        int cnt = 0;
        for (string s : st2)
        {
            auto it = st.find(s);
            if (it != st.end())
            {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}