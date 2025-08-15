#include <bits/stdc++.h>

using namespace std;

// 투포인터
vector<int> solution(vector<int> sequence, int k)
{
    vector<int> answer;
    int start = 0;
    int end = 0;
    int sum = 0;
    int len = INT_MAX;
    int first = 0;
    int last = 0;
    int n = sequence.size();
    for (end = 0; end < n; end++)
    {
        sum += sequence[end];
        while (start <= end && sum > k)
        {
            sum -= sequence[start++];
        }
        if (sum == k)
        {
            int tmpLen = end - start + 1;
            if (tmpLen < len)
            {
                len = tmpLen;
                first = start;
                last = end;
            }
        }
    }
    answer.push_back(first);
    answer.push_back(last);

    return answer;
}