#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<int>> mp;
void makeKeys(vector<string> attr, int idx, string key, int score)
{
    if (attr.size() == idx)
    {
        mp[key].push_back(score);
        return;
    }
    makeKeys(attr, idx + 1, key + attr[idx], score);
    makeKeys(attr, idx + 1, key + "-", score);
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    for (string str : info)
    {
        stringstream ss(str);
        string a, b, c, d;
        int score;
        ss >> a >> b >> c >> d >> score;
        vector<string> attr = {a, b, c, d};
        makeKeys(attr, 0, "", score);
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }
    // 쿼리
    for (string q : query)
    {
        stringstream ss(q);
        string a, and1, b, and2, c, and3, d;
        int score;
        ss >> a >> and1 >> b >> and2 >> c >> and3 >> d >> score;
        string queryKey = a + b + c + d;

        // if(mp.find(queryKey)==mp.end()){
        //     answer.push_back(0);
        //     continue;
        // }

        vector<int> v = mp[queryKey];
        auto it = lower_bound(v.begin(), v.end(), score);
        if (it == v.end())
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(v.end() - it);
        }
    }
    return answer;
}