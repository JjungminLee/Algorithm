#include <bits/stdc++.h>

using namespace std;
vector<string> answer;
vector<char> arr;

bool operators(pair<int, string> a, pair<int, string> b)
{
    return a.first > b.first;
}
int isMatching(vector<char> comb, vector<string> orders)
{
    int cnt = 0;

    for (auto &str : orders)
    {
        bool allMatch = true;

        for (char c : comb)
        {
            if (str.find(c) == string::npos)
            {
                allMatch = false;
                break;
            }
        }
        if (allMatch)
        {
            cnt++;
        }
    }

    return cnt;
}
void dfs(int depth, int start, vector<char> v, vector<string> orders, vector<pair<int, string>> &pair_v)
{

    if (depth == v.size())
    {
        bool flag = true;
        int num = isMatching(v, orders);

        if (num >= 2)
        {
            string str = "";
            for (int i = 0; i < v.size(); i++)
            {
                str += v[i];
            }
            pair_v.push_back({num, str});
        }
        return;
    }

    for (int i = start; i < arr.size(); i++)
    {
        v.push_back(arr[i]);
        dfs(depth, i + 1, v, orders, pair_v);
        v.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    set<char> st;
    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = 0; j < orders[i].size(); j++)
        {
            st.insert(orders[i][j]);
        }
    }
    for (auto it = st.begin(); it != st.end(); it++)
    {
        arr.push_back(*it);
    }

    for (int i : course)
    {
        vector<char> v;
        vector<pair<int, string>> pair_v;
        dfs(i, 0, v, orders, pair_v);
        sort(pair_v.begin(), pair_v.end(), operators);
        int maxNum = pair_v[0].first;
        for (int i = 0; i < pair_v.size(); i++)
        {

            if (maxNum == pair_v[i].first)
            {
                answer.push_back(pair_v[i].second);
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}