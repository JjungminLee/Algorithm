#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    int n = enroll.size();
    vector<int> parent(n, -1);

    for (int i = 0; i < enroll.size(); i++)
    {
        string cur = enroll[i];
        mp[cur] = i;
    }

    for (int i = 0; i < referral.size(); i++)
    {
        string par = referral[i];
        if (par != "-")
        {
            parent[i] = mp[par];
        }
    }

    vector<int> answer(n, 0);

    for (int i = 0; i < seller.size(); i++)
    {
        string str = seller[i];
        int idx = mp[str];
        int price = amount[i] * 100;
        // 부모 찾기
        while (1)
        {
            int passPrice = price / 10;
            int keep = price - passPrice;
            answer[idx] += keep;
            if (passPrice == 0)
                break;
            idx = parent[idx];
            if (idx == -1)
                break;
            price = passPrice;
        }
    }

    return answer;
}