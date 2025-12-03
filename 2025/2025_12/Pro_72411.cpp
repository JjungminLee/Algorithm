#include <bits/stdc++.h>

using namespace std;

vector<pair<string, int>> maxStrs;

bool compares(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool findStr(string target, string str)
{
    if (str.size() < target.size())
        return false;
    for (char ch : target)
    {
        if (str.find(ch) == string::npos)
            return false;
    }
    return true;
}

void backtracking(int idx, int depth, vector<char> v, vector<char> temp, vector<string> orders)
{
    if (depth == temp.size())
    {
        int cnt = 0;
        string tmpStr = "";
        for (int i = 0; i < temp.size(); i++)
        {
            tmpStr += temp[i];
        }
        for (int i = 0; i < orders.size(); i++)
        {
            if (findStr(tmpStr, orders[i]))
            {
                cnt++;
            }
        }
        maxStrs.push_back({tmpStr, cnt});
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        temp.push_back(v[i]);
        backtracking(i + 1, depth, v, temp, orders);
        temp.pop_back();
    }
}
vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    set<char> st;
    vector<char> v;
    for (string str : orders)
    {
        for (int i = 0; i < str.size(); i++)
        {
            st.insert(str[i]);
        }
    }
    for (char ch : st)
    {
        v.push_back(ch);
    }
    for (int i = 0; i < course.size(); i++)
    {
        maxStrs.clear();
        vector<char> temp;
        backtracking(0, course[i], v, temp, orders);
        sort(maxStrs.begin(), maxStrs.end(), compares);

        int maxNum = maxStrs[0].second;
        if (maxNum >= 2)
        {
            for (int j = 0; j < maxStrs.size(); j++)
            {
                if (maxStrs[j].second == maxNum)
                {
                    answer.push_back(maxStrs[j].first);
                }
                else if (maxStrs[j].second < maxNum)
                {
                    break;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}