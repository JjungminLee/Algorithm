#include <bits/stdc++.h>

using namespace std;

int solution(string my_string)
{
    int answer = 0;
    string str = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        int num = my_string[i] - '0';
        if (0 <= num && num <= 9)
        {
            str += my_string[i];
        }
        else
        {
            if (str == "")
                continue;
            int num = stoi(str);
            answer += num;
            str = "";
        }
    }
    if (!str.empty())
    {
        answer += stoi(str);
    }
    return answer;
}