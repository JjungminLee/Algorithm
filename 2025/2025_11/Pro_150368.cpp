#include <bits/stdc++.h>

using namespace std;

int discounts[4] = {10, 20, 30, 40};
int ansPeople = 0;
int ansPrice = 0;

// 할인율 조합
// 서비스 가입자 늘리기
// 이모티콘 판매액 최대한 늘리기

void dfs(int depth, vector<int> comb, vector<vector<int>> users, vector<int> emoticons)
{
    int curPeople = 0;
    int curPrice = 0;

    // dfs기준이 사람이 아니라 이모티콘이여야!
    // 이모티콘에 대해서 얼만큼의 할인율을 적용할건지가 핵심

    if (depth == emoticons.size())
    {
        for (int i = 0; i < users.size(); i++)
        {
            int userRate = users[i][0];
            int userPrice = users[i][1];

            int tot = 0;
            for (int j = 0; j < emoticons.size(); j++)
            {
                if (comb[j] >= userRate)
                {
                    int dis = 100 - comb[j];
                    double disRate = dis * 0.01;
                    tot += (emoticons[j] * disRate);
                }
            }
            if (tot >= userPrice)
            {
                curPeople++;
            }
            else
            {
                curPrice += tot;
            }
        }
        if (curPeople > ansPeople)
        {
            ansPeople = curPeople;
            ansPrice = curPrice;
        }
        else if (curPeople == ansPeople)
        {
            if (curPrice > ansPrice)
            {
                ansPrice = curPrice;
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        // 여기서 가지치기 해서 조합을 만들면 안됨
        // 여기서 가지치기 하면 하나라도 해당 안되면 comb에 안들어가는데
        // 하나라도 해당 안돼도 comb를 만든게 최대 임티 플러스 가입자, 구매비용이 될 수 있기 때문!
        comb.push_back(discounts[i]);
        dfs(depth + 1, comb, users, emoticons);
        comb.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;
    vector<int> combs;
    dfs(0, combs, users, emoticons);
    answer.push_back(ansPeople);
    answer.push_back(ansPrice);
    return answer;
}