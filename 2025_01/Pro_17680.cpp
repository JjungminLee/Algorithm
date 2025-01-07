#include <bits/stdc++.h>

using namespace std;
vector<string> cacheList;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }
    else
    {
        // LRU -> 최근에 사용한 항목은 맨 앞에 오래된 항목은 맨 뒤에
        for (string &city : cities)
        {
            transform(city.begin(), city.end(), city.begin(), ::toupper);
            auto it = find(cacheList.begin(), cacheList.end(), city);
            if (it != cacheList.end())
            {
                // cache hit -> 현재꺼를 지우고
                answer++;
                cacheList.erase(it);
            }
            else
            {
                if (cacheList.size() >= cacheSize)
                {
                    cacheList.pop_back();
                }
                // cache miss
                answer += 5;
            }
            // city는 맨 앞에 추가
            cacheList.insert(cacheList.begin(), city);
        }
    }

    return answer;
}