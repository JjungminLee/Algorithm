#include <bits/stdc++.h>
using namespace std;

vector<int> v = {3, 2, 1, 0, 1, 2, 3};
map<char, int> mp;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";
    int n = survey.size();
    for (int i = 0; i < n; i++)
    {
        int c = choices[i] - 1;
        int val = v[c];
        if (0 <= c && c <= 2)
        {
            mp[survey[i][0]] += val;
        }
        else if (4 <= c && c <= 6)
        {
            mp[survey[i][1]] += val;
        }
    }
    if (mp['R'] >= mp['T'])
    {
        answer += 'R';
    }
    else if (mp['R'] < mp['T'])
    {
        answer += 'T';
    }

    if (mp['C'] >= mp['F'])
    {
        answer += 'C';
    }
    else if (mp['C'] < mp['F'])
    {
        answer += 'F';
    }

    if (mp['J'] >= mp['M'])
    {
        answer += 'J';
    }
    else if (mp['J'] < mp['M'])
    {
        answer += 'M';
    }

    if (mp['A'] >= mp['N'])
    {
        answer += 'A';
    }
    else if (mp['A'] < mp['N'])
    {
        answer += 'N';
    }
    return answer;
}