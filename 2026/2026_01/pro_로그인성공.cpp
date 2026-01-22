#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    string answer = "";
    for (int i = 0; i < db.size(); i++)
    {
        vector<string> target = db[i];
        if (target[0] == id_pw[0] && target[1] == id_pw[1])
        {
            return "login";
        }
        if (target[0] == id_pw[0] && target[1] != id_pw[1])
        {
            answer = "wrong pw";
        }
        if (target[0] != id_pw[0] && target[1] != id_pw[1])
        {
            if (answer == "wrong pw")
                continue;
            answer = "fail";
        }
    }
    return answer;
}