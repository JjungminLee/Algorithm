#include <string>
#include <vector>

using namespace std;

int solution(int order)
{
    int answer = 0;
    string str = to_string(order);
    for (int i = 0; i < str.size(); i++)
    {
        int num = str[i] - '0';
        if (num == 3 || num == 6 || num == 9)
        {
            answer++;
        }
    }
    return answer;
}