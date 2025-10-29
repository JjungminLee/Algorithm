#include <bits/stdc++.h>

using namespace std;
// map사용하기
// 교집합은 min
// 합집합은 max
vector<string> v1;
vector<string> v2;
map<string, int> mp1;
map<string, int> mp2;
vector<string> intersect;
vector<string> unions;
int solution(string str1, string str2)
{
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    for (int i = 0; i < str1.size() - 1; i++)
    {
        string str = "";
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
        {
            str += (str1[i]);
            str += (str1[i + 1]);
            v1.push_back(str);
        }
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        string str = "";
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
        {
            str += (str2[i]);
            str += (str2[i + 1]);
            v2.push_back(str);
        }
    }
    for (int i = 0; i < v1.size(); i++)
    {
        mp1[v1[i]]++;
    }
    for (int i = 0; i < v2.size(); i++)
    {
        mp2[v2[i]]++;
    }
    // mp1을 돌면서 해당 key가 mp2에도 있으면 둘 중 더 큰 값을 합집합에 넣음
    // mp2는 Mp1에 해당하지 않는 것을 합집합에 넣음
    for (auto it = mp1.begin(); it != mp1.end(); it++)
    {
        auto key = it->first;
        auto val = it->second;
        auto it2 = mp2.find(key);
        // 존재함
        if (it2 != mp2.end())
        {
            auto key2 = it2->first;
            auto val2 = it2->second;
            int maxNum = max(val, val2);
            for (int i = 0; i < maxNum; i++)
            {
                unions.push_back(key);
            }
        }
        else
        {
            for (int i = 0; i < val; i++)
            {
                unions.push_back(key);
            }
        }
    }
    for (auto it = mp2.begin(); it != mp2.end(); it++)
    {
        string key = it->first;
        auto val = it->second;
        auto it2 = mp1.find(key);
        if (it2 != mp1.end())
        {
            continue;
        }
        else
        {
            for (int i = 0; i < val; i++)
            {
                unions.push_back(key);
            }
        }
    }

    // mp1을 돌면서 해당 key가 mp2에도 있을때만 둘 중 더 작은 값을 교집합에 넣음
    for (auto it = mp1.begin(); it != mp1.end(); it++)
    {
        auto key = it->first;
        auto val = it->second;
        auto it2 = mp2.find(key);
        // 존재함
        if (it2 != mp2.end())
        {
            auto key2 = it2->first;
            auto val2 = it2->second;
            int minNum = min(val, val2);
            for (int i = 0; i < minNum; i++)
            {
                intersect.push_back(key);
            }
        }
    }

    if (unions.size() == 0)
    {
        answer = 65536;
    }
    else
    {
        answer = intersect.size() * 65536 / unions.size();
    }

    return answer;
}