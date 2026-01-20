#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k)
{
    int answer = 0;
    for (int cur = i; cur <= j; cur++)
    {
        string str = to_string(cur);
        for (int l = 0; l < str.size(); l++)
        {
            int num = str[l] - '0';
            if (num == k)
            {
                answer++;
            }
        }
    }
    return answer;
}