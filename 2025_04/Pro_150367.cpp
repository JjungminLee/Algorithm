#include <bits/stdc++.h>
using namespace std;

bool check(const string &s, int l, int r, char parent)
{
    if (l > r)
        return true;
    int mid = (l + r) / 2;
    if (parent == '0' && s[mid] == '1')
        return false;
    return check(s, l, mid - 1, s[mid]) && check(s, mid + 1, r, s[mid]);
}

vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;
    for (auto num : numbers)
    {
        string s = bitset<64>(num).to_string();
        int first_one = s.find('1');
        s = s.substr(first_one); // 앞쪽 0 제거

        // 길이를 2^k - 1로 맞추기
        int len = s.length();
        int h = 0;
        while ((1LL << h) - 1 < len)
            h++;
        int target_len = (1LL << h) - 1;
        s = string(target_len - len, '0') + s; // 앞에 0 채워넣기

        // 재귀로 검증
        answer.push_back(check(s, 0, s.length() - 1, '1') ? 1 : 0);
    }
    return answer;
}
