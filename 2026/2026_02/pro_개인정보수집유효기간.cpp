#include <bits/stdc++.h>

using namespace std;

vector<string> v;
map<char, int> mp;
int toDays(string str)
{
    int y = stoi(str.substr(0, 4));
    int m = stoi(str.substr(5, 2));
    int d = stoi(str.substr(8, 2));
    return (y * 12 * 28) + (m * 28) + d;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    for (int i = 0; i < terms.size(); i++)
    {
        char ch = terms[i][0];
        int month = stoi(terms[i].substr(2));
        mp[ch] = month;
    }

    int todayDay = toDays(today);
    for (int i = 0; i < privacies.size(); i++)
    {
        string str = privacies[i].substr(0, 10);
        char ch = privacies[i][11];
        int start = toDays(str);
        int end = start + (28 * mp[ch]);
        if (end <= todayDay)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}