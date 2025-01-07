#include <bits/stdc++.h>

using namespace std;
list<string> cacheList;
// city 이름, cacheList내에서 city의 위치
unordered_map<string, list<string>::iterator> cacheMap;
int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }
    for (string &city : cities)
    {
        transform(city.begin(), city.end(), city.begin(), ::toupper);

        if (cacheMap.find(city) != cacheMap.end())
        {
            // hit
            cacheList.erase(cacheMap[city]); // list에서 현재 위치 제거
            answer++;
        }
        else
        {
            if (cacheList.size() >= cacheSize)
            {
                cacheMap.erase(cacheList.back());
                cacheList.pop_back();
            }
            answer += 5;
        }
        cacheList.push_front(city);         // list 맨앞에 추가
        cacheMap[city] = cacheList.begin(); // map에 위치 반영
    }

    return answer;
}