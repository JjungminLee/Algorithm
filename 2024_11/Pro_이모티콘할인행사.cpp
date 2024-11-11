#include <bits/stdc++.h>

using namespace std;

int datas[4] = {10, 20, 30, 40};

int ansAcession = 0;
int ansPrice = 0;
/*
경로가 아닌 dfs의 사용법 -> 백트래킹으로 생각하고 푸는게 맞았음!
 */
void dfs(int depth, vector<int> combination, vector<vector<int>> users, vector<int> emoticons)
{

    if (depth == emoticons.size())
    {

        int userSize = users.size();
        // 가입한 회원수
        int accessionCnt = 0;
        // 총 수익
        int totPrice = 0;
        for (int i = 0; i < userSize; i++)
        {
            // 유저 배열을 돌면서 이모티콘을 얼마나 살 수 있는지 판단
            int discountRatio = users[i][0];
            int maxPrice = users[i][1];
            int sum = 0;
            for (int j = 0; j < emoticons.size(); j++)
            {
                // 이모티콘 할인율이 최소할인율보다 크거나 같은경우
                if (discountRatio <= combination[j])
                {
                    int discount_price = emoticons[j] * (100 - combination[j]) / 100;

                    sum += discount_price;
                }
            }

            if (sum >= maxPrice)
            {

                accessionCnt += 1;
                // 이모티콘 플러스에 가입하면 구매취소함
            }
            else
            {
                totPrice += sum;
            }
        }
        // 문제를 잘 읽기 -> 이모티콘 가입한 사람 수 업데이트
        if (accessionCnt > ansAcession)
        {
            ansAcession = accessionCnt;
            ansPrice = totPrice;
        }
        else if (accessionCnt == ansAcession)
        {
            // 같다면  총가격만 업데이트
            if (ansPrice < totPrice)
            {
                ansPrice = totPrice;
            }
        }

        return;
    }
    else
    {
        // 항상 0부터 시작해서 40 40 20 40 같은것도 가능하게
        for (int i = 0; i < 4; i++)
        {
            combination.push_back(datas[i]);
            // i를 그대로 넘겨서 중복조합 허용
            //{10,10,10,10} 같은것도 허용하게 해야함
            dfs(depth + 1, combination, users, emoticons);
            combination.pop_back();
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;
    vector<int> combinations;
    dfs(0, combinations, users, emoticons);
    answer.push_back(ansAcession);
    answer.push_back(ansPrice);
    cout << ansAcession << " " << ansPrice << endl;
    return answer;
}

int main()
{
    // vector<vector<int>> v1 = {{40, 10000},
    //                           {25, 10000}};
    // vector<int> v2 = {7000, 9000};
    vector<vector<int>> v1 = {{40, 2900},
                              {23, 10000},
                              {11, 5200},
                              {5, 5900},
                              {40, 3100},
                              {27, 9200},
                              {32, 6900}};
    vector<int> v2 = {1300, 1500, 1600, 4900};

    solution(v1, v2);
}