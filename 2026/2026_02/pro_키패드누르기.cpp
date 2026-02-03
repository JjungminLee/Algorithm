#include <bits/stdc++.h>

using namespace std;
map<int, pair<int, int>> mp;

char func(string hand, int num, int &lx, int &ly, int &rx, int &ry)
{
    if (num == 1 || num == 4 || num == 7)
    {
        lx = mp[num].first;
        ly = mp[num].second;
        return 'L';
    }
    else if (num == 3 || num == 6 || num == 9)
    {
        rx = mp[num].first;
        ry = mp[num].second;
        return 'R';
    }
    else if (num == 2 || num == 5 || num == 8 || num == 0)
    {
        int nx = mp[num].first;
        int ny = mp[num].second;

        int rd = abs(nx - rx) + abs(ny - ry);
        int ld = abs(nx - lx) + abs(ny - ly);
        if (rd < ld)
        {
            rx = mp[num].first;
            ry = mp[num].second;
            return 'R';
        }
        else if (rd > ld)
        {
            lx = mp[num].first;
            ly = mp[num].second;
            return 'L';
        }
        else
        {
            if (hand == "right")
            {
                rx = mp[num].first;
                ry = mp[num].second;
                return 'R';
            }
            else if (hand == "left")
            {
                lx = mp[num].first;
                ly = mp[num].second;
                return 'L';
            }
        }
    }
}
string solution(vector<int> numbers, string hand)
{
    string answer = "";
    mp[1] = {0, 0};
    mp[2] = {0, 1};
    mp[3] = {0, 2};
    mp[4] = {1, 0};
    mp[5] = {1, 1};
    mp[6] = {1, 2};
    mp[7] = {2, 0};
    mp[8] = {2, 1};
    mp[9] = {2, 2};
    mp[0] = {3, 1};
    int lx = 0;
    int ly = 0;
    int rx = 0;
    int ry = 0;

    lx = 3;
    ly = 0;
    rx = 3;
    ry = 2;

    for (int i = 0; i < numbers.size(); i++)
    {
        answer += func(hand, numbers[i], lx, ly, rx, ry);
    }
    return answer;
}