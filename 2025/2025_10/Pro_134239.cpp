#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;
    v.push_back(k);
    while (1)
    {
        if (k <= 1)
        {
            break;
        }
        else if (k % 2 == 0)
        {
            k /= 2;
            n++;
        }
        else if (k % 2 == 1)
        {
            k *= 3;
            k += 1;
            n++;
        }
        v.push_back(k);
    }

    for (int i = 0; i < ranges.size(); i++)
    {
        int a = ranges[i][0];
        int b = ranges[i][1];
        double d = 0;
        if (b >= 0)
        {
            b = n - b;
        }
        else
        {
            b = n + b;
        }

        if (a <= b)
        {
            for (int j = a; j < b; j++)
            {
                d += (v[j] + v[j + 1]) / 2.0;
            }
        }
        else
        {
            d = -1;
        }
        answer.push_back(d);
    }

    return answer;
}