#include <bits/stdc++.h>

using namespace std;

int toSec(string time)
{
    int pos1 = time.find(':');
    int pos2 = time.find(':', pos1 + 1);

    string h = time.substr(0, pos1);
    string m = time.substr(pos1 + 1, pos2 - pos1 - 1);
    string s = time.substr(pos2 + 1);

    int hh = stoi(h);
    int mm = stoi(m);
    int ss_ = stoi(s);
    return 3600 * hh + 60 * mm + ss_;
}

string toHHM(int sec)
{
    long long h = sec / 3600;
    sec %= 3600;
    long long m = sec / 60;
    long long s = sec % 60;
    char buf[16];
    sprintf(buf, "%02lld:%02lld:%02lld", h, m, s);
    return string(buf);
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "";
    int play = toSec(play_time);
    int adv = toSec(adv_time);
    if (play == adv)
        return "00:00:00";

    vector<long long> diff(play + 2, 0);
    vector<long long> viewers(play + 2, 0);
    vector<long long> pSum(play + 2, 0);

    for (int i = 0; i < logs.size(); i++)
    {
        int dash = logs[i].find("-");
        string a = logs[i].substr(0, dash);
        string b = logs[i].substr(dash + 1);
        int start = toSec(a);
        int end = toSec(b);
        diff[start] += 1;
        diff[end] -= 1;
        // 차분을 사용해 +1 -1 기법
    }

    long long cur = 0;
    // 동시 사용자 수
    for (int i = 0; i <= play; i++)
    {
        cur += diff[i];
        viewers[i] = cur;
    }

    // 시간당 누적합
    pSum[0] = viewers[0];
    for (int i = 1; i <= play; i++)
    {
        pSum[i] = pSum[i - 1] + viewers[i];
    }

    long long ansSum = pSum[adv - 1];
    int ansStart = 0;

    // 광고시작 시간
    for (int i = 1; i <= play - adv; i++)
    {
        int end = i + adv - 1;
        long long curSum = pSum[end] - pSum[i - 1];
        if (curSum > ansSum)
        {
            ansStart = i;
            ansSum = curSum;
        }
    }

    return toHHM(ansStart);
}