#include <bits/stdc++.h>
using namespace std;

long long solution(string expression)
{
    long long answer = 0;
    int startIdx = 0;
    vector<string> v;
    unordered_set<string> opSet;
    for (int i = 0; i < expression.size(); i++)
    {

        if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+')
        {
            string temp = "";
            string calculate = "";
            for (int j = startIdx; j < i; j++)
            {
                temp += expression[j];
            }
            v.push_back(temp);
            calculate += expression[i];
            v.push_back(calculate);
            opSet.insert(calculate);

            startIdx = i + 1;
        }
    }
    string temp = "";
    for (int i = startIdx; i < expression.size(); i++)
    {
        temp += expression[i];
    }
    v.push_back(temp);

    // vector<string> cal(opSet.begin(),opSet.end());
    vector<string> cal = {"+", "-", "*"};
    sort(cal.begin(), cal.end());

    do
    {
        vector<string> tempV = v;
        for (int i = 0; i < cal.size(); i++)
        {
            for (int j = 0; j < tempV.size(); j++)
            {
                if (tempV[j] == cal[i])
                {
                    long long left = stoll(tempV[j - 1]);
                    long long right = stoll(tempV[j + 1]);
                    long long res;

                    if (cal[i] == "-")
                    {
                        res = (left - right);
                    }
                    else if (cal[i] == "+")
                    {
                        res = (left + right);
                    }
                    else if (cal[i] == "*")
                    {
                        res = (left * right);
                    }
                    // j+1까지 삭제가 아님!
                    tempV.erase(tempV.begin() + j - 1, tempV.begin() + j + 2);
                    tempV.insert(tempV.begin() + j - 1, to_string(res));

                    // j인덱스 위치를 계산 완료한값으로 포인터 위치 변경!
                    j = max(j - 1, 0);
                }
            }
        }
        answer = max(answer, abs(stoll(tempV[0])));
    } while (next_permutation(cal.begin(), cal.end()));
    return answer;
}