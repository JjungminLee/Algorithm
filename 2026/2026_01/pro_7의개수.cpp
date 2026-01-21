#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> array)
{
    int answer = 0;
    for (int i = 0; i < array.size(); i++)
    {
        string str = to_string(array[i]);

        for (int j = 0; j < str.size(); j++)
        {
            int num = str[j] - '0';

            if (num == 7)
            {
                answer++;
            }
        }
    }
    return answer;
}