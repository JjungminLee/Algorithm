#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    vector<int> v;
    for (string &str : timetable)
    {
        int hour = stoi(str.substr(0, 2));
        int time = stoi(str.substr(3, 4));
        int tot = 60 * hour + time;
        v.push_back(tot);
    }
    sort(v.begin(), v.end());
    int start = 9 * 60;
    int end = 540 + (n - 1) * t;

    int conLastTime = 0;
    int currIdx = 0;
    for (int i = 0; i < n; i++)
    {
        int capacity = m;
        while (currIdx < v.size() && v[currIdx] <= start && capacity > 0)
        {
            if (i == n - 1 && capacity == 1)
            {
                // 현재 시간에서 1만 빼주면 됐음!! 매우 단순!!
                conLastTime = v[currIdx] - 1;
            }
            capacity--;
            currIdx++;
        }
        // timetable 다 돌아도 남은경우
        if (i == n - 1 && capacity > 0)
        {
            conLastTime = end;
        }
        start += t;
    }
    int hour = conLastTime / 60;
    int minute = conLastTime % 60;
    char buffer[6];
    sprintf(buffer, "%02d:%02d", hour, minute);

    return buffer;
}