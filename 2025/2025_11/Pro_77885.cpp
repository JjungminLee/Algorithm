#include <bits/stdc++.h>
using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    for (long long num : numbers)
    {
        // num에서 비트 연산을 하면서 다른 비트의 수가 1개이상 2개이하인 경우를 찾기
        long long target = 0;
        if (num % 2 == 0)
        {
            // num이 짝수 일때 -> 어차피 맨뒤가 0이기 때문에 1만 오른쪽 뒤에 넣어줘도 조건 만족함
            // 오른쪽 뒤에 1을 넣는건 사실상 1을 더하는거랑 마찬가지
            target = num + 1;
        }
        else
        {
            // num이 홀수 일때  -> 맨뒤가 1이기에 맨 왼쪽에 1을 넣어주고 그 1앞에 있는 1을 0으로 바꾸기
            long long bit = 1;

            // 오른쪽부터 옮겨가면서 처음으로 0이 나오는 시점을 찾기 (그리디로 찾는거, 왼쪽부터 찾으면 겁나커짐)
            while ((num & bit) != 0)
            {
                bit <<= 1;
            }
            // bit+num을 하면 15인데 1111
            // 원하는게 1011 임
            // 그러면 bit의 자리인 4보다 1작은 3번째 자리가 0이되면 됨
            // 그러면 bit+num 에서 bit/2를 하면됨! bit/2가 bit>>1 b*2^(-k)

            target = num + bit - (bit >> 1);
        }
        answer.push_back(target);
    }
    return answer;
}