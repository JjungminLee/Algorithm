#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;
vector<pair<int, int>> candidate;

void findCandidate(int start, int end)
{
    for (int i = 0; i < candidate.size(); i++)
    {
        int startc = candidate[i].first;
        int endc = candidate[i].second;
        if (start >= endc)
        {
            candidate[i] = {start, end};
            return;
        }
    }
    candidate.push_back({start, end});
}
int solution(vector<vector<string>> book_time)
{
    int answer = 1;
    for (int i = 0; i < book_time.size(); i++)
    {
        string start = book_time[i][0];
        string end = book_time[i][1];

        string startHour = start.substr(0, 2);
        string startMin = start.substr(3, 4);
        int startHourInt = stoi(startHour);
        int startMinInt = stoi(startMin);
        int startInt = startHourInt * 60 + startMinInt;

        string endHour = end.substr(0, 2);
        string endMin = end.substr(3, 4);
        int endHourInt = stoi(endHour);
        int endMinInt = stoi(endMin);
        int endInt = endHourInt * 60 + endMinInt + 10;

        v.push_back({startInt, endInt});
    }
    sort(v.begin(), v.end());
    candidate.push_back({v[0].first, v[0].second});
    for (int i = 1; i < v.size(); i++)
    {
        int start = v[i].first;
        int end = v[i].second;
        findCandidate(start, end);
    }
    answer = candidate.size();

    return answer;
}