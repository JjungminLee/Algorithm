#include <bits/stdc++.h>

using namespace std;
int one;

vector<int> v;

bool compares(vector<int> a, vector<int> b)
{
    if (a[one] == b[one])
    {
        return a[0] > b[0];
    }
    return a[one] < b[one];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;
    one = col - 1;
    sort(data.begin(), data.end(), compares);

    for (int i = row_begin; i <= row_end; i++)
    {
        vector<int> tmp = data[i - 1];
        int cnt = 0;
        for (int j : tmp)
        {
            cnt += (j % i);
        }
        v.push_back(cnt);
    }

    answer = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        answer ^= v[i];
    }

    return answer;
}