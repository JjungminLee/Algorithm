#include <bits/stdc++.h>

using namespace std;
map<char, char> mp;

string solution(string rsp)
{
    string answer = "";
    mp['2'] = '0';
    mp['0'] = '5';
    mp['5'] = '2';

    for (int i = 0; i < rsp.size(); i++)
    {
        answer += mp[rsp[i]];
    }

    return answer;
}