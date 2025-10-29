#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
unordered_map<ll, ll> parent;

ll find(ll num)
{
    if (parent.find(num) == parent.end())
    {
        parent[num] = (num + 1);
        return num;
    }
    return parent[num] = find(parent[num]);
}
vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;
    for (ll l : room_number)
    {
        answer.push_back(find(l));
    }
    return answer;
}