#include <bits/stdc++.h>
int row, col;

using namespace std;
vector<vector<int>> candidate;
void backtracking(int depth, int start, vector<int> v, vector<vector<string>> relation)
{
    if (depth == v.size())
    {
        // 유일성 판단
        set<string> st;
        for (int i = 0; i < row; i++)
        {
            string key = "";
            for (int j = 0; j < v.size(); j++)
            {
                key += relation[i][v[j]] + "|";
            }
            st.insert(key);
        }
        if (st.size() != row)
        {
            return;
        }
        // 최소성 판단

        for (int i = 0; i < candidate.size(); i++)
        {

            bool isSubset = true;
            vector<int> subcan = candidate[i];
            for (int j = 0; j < subcan.size(); j++)
            {
                // 현재 v안에 candidate[i][j]가 있으면 v가 부분집합이 아니게됨
                if (find(v.begin(), v.end(), subcan[i]) == v.end())
                {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset)
            {
                return;
            }
        }
        candidate.push_back(v);
    }
    for (int i = start; i < col; i++)
    {
        v.push_back(i);
        backtracking(depth, i + 1, v, relation);
        v.pop_back();
    }
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    row = relation.size();
    col = relation[0].size();
    // 컬럼 몇개 선택할건지
    for (int i = 1; i <= col; i++)
    {
        vector<int> sub;
        backtracking(i, 0, sub, relation);
    }
    return candidate.size();
}