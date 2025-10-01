#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int solution(vector<int> elements)
{
    int answer = 0;
    for (int i : elements)
    {
        v.push_back(i);
    }
    for (int i : elements)
    {
        v.push_back(i);
    }

    set<int> st;

    for (int i = 0; i < elements.size(); i++)
    {
        int left = 0;
        int right = i;
        while (right < v.size())
        {
            int sum = 0;
            for (int j = left; j <= right; j++)
            {
                sum += v[j];
            }
            st.insert(sum);
            left++;
            right++;
        }
    }

    answer += st.size();

    return answer;
}