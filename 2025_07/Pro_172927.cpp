#include <bits/stdc++.h>

using namespace std;
int arr[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
int ans = INT_MAX;
void backTracking(int picksCnt, int toolCnt, vector<int> picks, vector<int> v, vector<int> mineralsV)
{
    if (toolCnt > picksCnt && v.size() == picksCnt)
    {
        int tempAns = 0;
        int mineralIdx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int a = v[i];
            for (int j = mineralIdx; j < mineralIdx + 5 && j < mineralsV.size(); j++)
            {
                int b = mineralsV[j];
                tempAns += arr[a][b];
            }
            mineralIdx += 5;
        }
        ans = min(ans, tempAns);
        return;
    }

    if (toolCnt <= picksCnt && v.size() == toolCnt)
    {
        int tempAns = 0;
        int mineralIdx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            int a = v[i];
            for (int j = mineralIdx; j < mineralIdx + 5 && j < mineralsV.size(); j++)
            {
                int b = mineralsV[j];
                tempAns += arr[a][b];
            }
            mineralIdx += 5;
        }
        ans = min(ans, tempAns);
        return;
    }
    for (int i = 0; i < picks.size(); i++)
    {
        if (picks[i] > 0)
        {
            v.push_back(i);
            picks[i]--;
            backTracking(picksCnt, toolCnt, picks, v, mineralsV);
            picks[i]++;
            v.pop_back();
        }
    }
}

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 0;
    vector<int> mineralsV;

    for (int i = 0; i < minerals.size(); i++)
    {
        if (minerals[i] == "diamond")
        {
            mineralsV.push_back(0);
        }
        else if (minerals[i] == "iron")
        {
            mineralsV.push_back(1);
        }
        else if (minerals[i] == "stone")
        {
            mineralsV.push_back(2);
        }
    }

    int toolCnt = minerals.size() / 5;
    if (toolCnt > 0 && minerals.size() % 5 != 0)
    {
        toolCnt += 1;
    }
    int picksCnt = 0;
    for (int i = 0; i < picks.size(); i++)
    {
        picksCnt += picks[i];
    }
    vector<int> v;
    backTracking(picksCnt, toolCnt, picks, v, mineralsV);

    answer = ans;

    return answer;
}