#include <string>
#include <vector>

using namespace std;
int stdCnt;
int maxAns;
vector<int> maxV;
void dfs(int idx, int cnt, vector<int> &v, vector<int> info)
{
    if (idx == 11)
    {
        if (cnt > stdCnt)
        {
            return;
        }
        // 매우 중요! 마지막에 몰아주기!!
        v[10] += stdCnt - cnt;
        int apeach = 0;
        int lion = 0;
        for (int i = 0; i < 11; i++)
        {
            if (info[i] > v[i])
            {
                apeach += (10 - i);
            }
            else if (info[i] < v[i])
            {
                lion += (10 - i);
            }
        }
        if (lion > apeach)
        {
            int diff = lion - apeach;
            if (maxAns < diff)
            {
                maxAns = diff;
                maxV = v;
            }
            else if (maxAns == diff)
            {
                for (int i = 10; i >= 0; i--)
                {
                    // 라이언이 가장 큰 점수 차이로 우승할 수 있는 방법이 여러 가지 일 경우, 가장 낮은 점수를 더 많이 맞힌 경우
                    if (v[i] > maxV[i])
                    {
                        maxV = v;
                        break;
                    }
                    else if (v[i] < maxV[i])
                    {
                        break;
                    }
                }
            }
        }
        // 원복시켜야! 다른 tc에서도 쓸수 있음
        v[10] -= stdCnt - cnt;
        return;
    }

    // 점수 획득
    if (stdCnt >= cnt + (info[idx] + 1))
    {
        v[idx] = (info[idx] + 1);
        dfs(idx + 1, cnt + info[idx] + 1, v, info);
        v[idx] = 0;
    }

    // 점수 획득 x
    dfs(idx + 1, cnt, v, info);
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    stdCnt = n;
    vector<int> v(info.size());
    dfs(0, 0, v, info);
    if (maxV.size() == 0)
    {
        answer.push_back(-1);
        return answer;
    }
    return maxV;
}