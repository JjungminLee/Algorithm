#include <bits/stdc++.h>
using namespace std;
// 포화 이진트리 -> 자식이 꽉참 (오,왼 다)
// 완전 이진트리 -> 왼쪽이 다 참
bool check(string s, int left, int right, char parent)
{
    if (left > right)
    {
        // 오른쪽에서 오른쪽으로 가는 right가 비어있는경우 -> 끝내야
        return true;
    }
    int mid = (left + right) / 2;
    if (parent == '0' && s[mid] == '1')
    {
        // 부모가 0인데 현재 노드는 1일수 없음
        return false;
    }
    return check(s, left, mid - 1, s[mid]) && check(s, mid + 1, right, s[mid]);
}
vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        string s = bitset<64>(numbers[i]).to_string();
        int firstOne = s.find('1');
        s = s.substr(firstOne);
        // 완전 이진트리로 만들기

        int len = s.length();
        int treeLen = 1;
        while (treeLen - 1 < len)
        {
            treeLen <<= 1;
        }
        treeLen--;                          // (2^h)-1
        s = string(treeLen - len, '0') + s; // 앞에 treeLen - len만큼 0을 이어붙임

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