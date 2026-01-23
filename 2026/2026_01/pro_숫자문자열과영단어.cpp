#include <bits/stdc++.h>

using namespace std;
map<string, char> mp;

int solution(string s)
{
    int answer = 0;
    string str = "";
    mp["zero"] = '0';
    mp["one"] = '1';
    mp["two"] = '2';
    mp["three"] = '3';
    mp["four"] = '4';
    mp["five"] = '5';
    mp["six"] = '6';
    mp["seven"] = '7';
    mp["eight"] = '8';
    mp["nine"] = '9';
    int idx = 0;
    string tmp = "";
    while (idx < s.size())
    {
        char ch = s[idx];
        if ('0' <= ch && ch <= '9')
        {
            str.push_back(ch);
            tmp.clear();
            idx++;
            continue;
        }
        // 일반 문자면
        tmp.push_back(ch);

        // map에 문자열이 있는지
        auto it = mp.find(tmp);
        if (it != mp.end())
        {
            str.push_back(it->second);
            tmp.clear();
        }
        idx++;
    }

    return stoi(str);
}