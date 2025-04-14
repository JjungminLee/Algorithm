#include <bits/stdc++.h>
using namespace std;
set<string> st;
vector<int> arr[10001];

int n;
map<string, int> mp;
vector<pair<string, int>> v;
vector<vector<string>> ans;

string findKey(int val)
{
    for (int i = 0; i < v.size(); i++)
    {
        string key = v[i].first;
        int value = v[i].second;
        if (value == val)
        {
            return key;
        }
    }
    return "";
}

int findTicketsIdx(string curr, string next, vector<vector<string>> tickets, vector<bool> visited)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        if (!visited[i] && tickets[i][0] == curr && tickets[i][1] == next)
        {
            return i;
        }
    }
    return -1;
}

void dfs(int idx, vector<string> sub, int ticketSize, vector<bool> visited, vector<vector<string>> tickets)
{
    if (sub.size() == ticketSize)
    {
        ans.push_back(sub);
        return;
    }
    for (int nextIdx : arr[idx])
    {
        string nextKey = findKey(nextIdx);
        string curKey = findKey(idx);
        int ticketIdx = findTicketsIdx(curKey, nextKey, tickets, visited);
        if (!visited[ticketIdx] && ticketIdx != -1)
        {
            visited[ticketIdx] = true;
            sub.push_back(nextKey);

            dfs(nextIdx, sub, ticketSize, visited, tickets);

            sub.pop_back();
            visited[ticketIdx] = false; // 꼼꼼히 봐주기!
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    for (int i = 0; i < tickets.size(); i++)
    {
        st.insert(tickets[i][0]);
        st.insert(tickets[i][1]);
    }
    n = tickets.size();
    int idx = 0;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        v.push_back({*it, idx});
        mp[*it] = idx;
        idx++;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        int start = mp[tickets[i][0]];
        int end = mp[tickets[i][1]];
        arr[start].push_back(end);
        // 알파벳 순으로 정렬해야 그 다음에 갈 것들은!
        sort(arr[start].begin(), arr[start].end());
    }

    int icn = mp["ICN"];
    vector<string> vv;
    vector<bool> visited(tickets.size() + 1);
    vv.push_back("ICN");
    dfs(icn, vv, tickets.size() + 1, visited, tickets);
    answer = ans[0];

    return answer;
}