#include <bits/stdc++.h>

using namespace std;

bool check(string s, int left, int right, char parent)
{
    if (left > right)
    {
        return true;
    }

    int mid = (left + right) / 2;
    // 부모가 0인데 현재노드가 1일 수 없음
    if (parent == '0' && s[mid] == '1')
    {
        return false;
    }
    return check(s, left, mid - 1, s[mid]) && check(s, mid + 1, right, s[mid]);
}

vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long num = numbers[i];
        string s = bitset<64>(num).to_string();
        int firstOne = s.find('1');
        s = s.substr(firstOne);
        int len = s.length();
        int treeLen = 1;
        // 완전 이진트리 구조로 변환하기
        while (treeLen - 1 < len)
        {
            treeLen <<= 1;
        }
        treeLen -= 1;
        s = string(treeLen - len, '0') + s;
        if (check(s, 0, s.length() - 1, '1'))
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }
    return answer;
}