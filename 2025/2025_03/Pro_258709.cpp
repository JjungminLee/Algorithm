#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> combinations;

void backTracking(int depth, int start, vector<int> v, int diceCnt)
{

    // 조합을 만들고
    if (depth == v.size())
    {

        combinations.push_back(v);

        return;
    }

    for (int i = start; i < diceCnt; i++)
    {
        v.push_back(i);
        backTracking(depth, i + 1, v, diceCnt);
        v.pop_back();
    }
}

int getSumCount(vector<int> &combA, vector<int> &combB, vector<vector<int>> dice)
{
    map<int, int> sumCountA;
    int firstDiceA = combA[0];
    for (int i = 0; i < 6; i++)
    {
        int diceNum = dice[firstDiceA][i];
        sumCountA[diceNum]++;
    }
    for (int i = 1; i < combA.size(); i++)
    {
        int diceIdx = combA[i];
        map<int, int> newSumCount;
        for (auto it = sumCountA.begin(); it != sumCountA.end(); it++)
        {
            int currSum = it->first;
            int currCnt = it->second;
            for (int j = 0; j < 6; j++)
            {
                int diceSum = dice[diceIdx][j];
                int newSum = diceSum + currSum;
                newSumCount[newSum] += currCnt;
            }
        }
        sumCountA = newSumCount;
    }

    map<int, int> sumCountB;
    int firstDiceB = combB[0];
    for (int i = 0; i < 6; i++)
    {
        int diceNum = dice[firstDiceB][i];
        sumCountB[diceNum]++;
    }
    for (int i = 1; i < combB.size(); i++)
    {
        int diceIdx = combB[i];
        map<int, int> newSumCount;
        for (auto it = sumCountB.begin(); it != sumCountB.end(); it++)
        {
            int currSum = it->first;
            int currCnt = it->second;
            for (int j = 0; j < 6; j++)
            {
                int diceSum = dice[diceIdx][j];
                int newSum = diceSum + currSum;
                newSumCount[newSum] += currCnt;
            }
        }
        sumCountB = newSumCount;
    }
    vector<int> prefixB(60001, 0);
    // map->vector로
    for (auto [sumB, cntB] : sumCountB)
    {
        prefixB[sumB] += cntB;
    }
    // vector 상태에서 누적합
    for (int i = 1; i < 60001; i++)
        prefixB[i] += prefixB[i - 1];

    // A의 점수합이 B보다 큰 경우의 수 계산
    int winCount = 0;
    for (auto [sumA, cntA] : sumCountA)
    {
        if (sumA == 0)
            continue;
        winCount += cntA * prefixB[sumA - 1]; // B가 sumA보다 작은 경우 수
    }

    return winCount;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;
    int diceCnt = dice.size();
    int halfDice = diceCnt / 2;
    vector<int> v;
    backTracking(halfDice, 0, v, diceCnt);
    vector<pair<int, int>> sum;

    for (int i = 0; i < combinations.size(); i++)
    {
        vector<int> combB;
        combB.resize(halfDice);
        // a의 조합 combinations[i]
        //  b의 조합
        int idx = 0;
        for (int j = 0; j < diceCnt; j++)
        { // 1부터 6이 아니라 진짜 조합 개수
            auto it = find(combinations[i].begin(), combinations[i].end(), j);
            if (it == combinations[i].end())
            {
                combB[idx] = j;
                idx++;
            }
        }
        idx = 0;
        vector<int> combA;
        combA.resize(halfDice);
        for (int j = 0; j < combinations[i].size(); j++)
        {
            combA[idx] = combinations[i][j];
            idx++;
        }
        int num = getSumCount(combA, combB, dice);
        sum.push_back({num, i});
    }
    sort(sum.begin(), sum.end(), compare);
    int ansIdx = sum[0].second;
    for (int i = 0; i < combinations[ansIdx].size(); i++)
    {
        answer.push_back(combinations[ansIdx][i] + 1);
    }

    return answer;
}