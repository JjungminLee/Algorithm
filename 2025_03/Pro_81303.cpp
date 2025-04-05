#include <bits/stdc++.h>
using namespace std;
vector<bool> v;
vector<int> del;
string solution(int n, int k, vector<string> cmd)
{
    string answer = "";
    for (int i = 0; i < n; i++)
    {
        v.push_back(true);
    }
    int curPos = k;
    for (int i = 0; i < cmd.size(); i++)
    {
        string str = cmd[i];
        if (str[0] == 'D')
        {
            int x = stoi(str.substr(2));
            while (x > 0 && curPos < v.size() - 1)
            {
                curPos++;
                if (v[curPos])
                    x--;
            }
        }
        else if (str[0] == 'C')
        {
            int isEnd = true;
            int delPos = curPos;
            del.push_back(delPos);
            for (int j = curPos + 1; j < v.size(); j++)
            {
                if (v[j])
                {
                    curPos = j;
                    isEnd = false;
                    break;
                }
            }
            if (isEnd)
            {
                // 문제 잘 읽기 -> 바로 윗행
                for (int j = curPos - 1; j >= 0; j--)
                {
                    if (v[j])
                    {
                        curPos = j;
                        break;
                    }
                }
            }
            v[delPos] = false;
        }
        else if (str[0] == 'U')
        {

            int x = stoi(str.substr(2));

            while (x > 0 && curPos > 0)
            {
                curPos--; // 얜 계속 줄여야 false는 skip해야함
                if (v[curPos])
                    x--;
            }
        }
        else if (str[0] == 'Z')
        {
            if (!del.empty())
            {
                int num = del[del.size() - 1];
                del.pop_back();
                v[num] = true;
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            answer += "O";
        }
        else
        {
            answer += "X";
        }
    }
    return answer;
}