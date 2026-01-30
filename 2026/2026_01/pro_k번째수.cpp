#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> tmp;
        int a = commands[i][0];
        int b = commands[i][1];
        int c = commands[i][2];
        a--;
        b--;
        c--;
        for (int j = a; j <= b; j++)
        {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[c]);
    }
    return answer;
}