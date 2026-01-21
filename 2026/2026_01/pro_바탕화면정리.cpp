#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    vector<int> answer;

    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;
    for (int i = 0; i < wallpaper.size(); i++)
    {
        string str = wallpaper[i];
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '#')
            {
                minX = min(i, minX);
                minY = min(j, minY);
                maxX = max(i + 1, maxX);
                maxY = max(j + 1, maxY);
            }
        }
    }
    answer.push_back(minX);
    answer.push_back(minY);
    answer.push_back(maxX);
    answer.push_back(maxY);

    return answer;
}