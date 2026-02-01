#include <bits/stdc++.h>

using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    vector<int> v;
    map<char, int> mp;
    for (int i = 0; i < Y.size(); i++)
    {
        mp[Y[i]]++;
    }
    for (int i = 0; i < X.size(); i++)
    {
        char ch = X[i];

        if (mp[ch] > 0)
        {
            v.push_back(ch - '0');
            mp[ch]--;
        }
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < v.size(); i++)
    {
        answer += (to_string(v[i]));
    }
    if (answer == "")
    {
        return "-1";
    }
    int zcount = 0;
    bool flag = true;
    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == '0')
        {
            zcount++;
        }
        else
        {
            flag = false;
        }
    }
    if (flag && zcount > 1)
    {
        return "0";
    }

    return answer;
}