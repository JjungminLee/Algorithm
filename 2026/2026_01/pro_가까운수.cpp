#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
int solution(vector<int> array, int n)
{
    int answer = 0;
    for (int i = 0; i < array.size(); i++)
    {
        v.push_back({abs(n - array[i]), array[i]});
    }
    sort(v.begin(), v.end());
    answer = v[0].second;
    return answer;
}