#include <bits/stdc++.h>

using namespace std;
map<string, int> mp;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "";
    int i = 0;
    int j = 0;
    for (string g : goal)
    {
        if (i < cards1.size() && cards1[i] == g)
        {
            i++;
        }
        else if (j < cards2.size() && cards2[j] == g)
        {
            j++;
        }
        else
        {
            return "No";
        }
    }
    return "Yes";
}