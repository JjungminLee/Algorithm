#include <bits/stdc++.h>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    for (int i = 0; i < new_id.size(); i++)
    {
        char c = new_id[i];
        if (c == '-' || c == '_' || c == '.' || isdigit(c) || islower(c))
        {
            answer += c;
        }
    }

    size_t it;
    while ((it = answer.find("..")) != string::npos)
    {
        answer.replace(it, 2, ".");
    }

    while (answer.size() && answer[0] == '.')
    {
        answer.erase(0, 1);
    }

    while (answer.size() && answer[answer.size() - 1] == '.')
    {
        answer.erase(answer.size() - 1, 1);
    }

    if (answer.size() == 0)
    {
        answer += "a";
    }

    if (answer.size() >= 16)
    {
        string nStr = "";
        for (int i = 0; i < 15; i++)
        {
            nStr += answer[i];
        }
        answer = nStr;
    }
    while (answer.size() && answer[answer.size() - 1] == '.')
    {
        answer.erase(answer.size() - 1, 1);
    }
    while (answer.size() < 3)
    {
        answer += answer[answer.size() - 1];
    }

    return answer;
}