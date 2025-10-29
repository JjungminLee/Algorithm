#include <bits/stdc++.h>
using namespace std;
set<set<string>> allCases;
/*
중복관리가 힘들때는 => set을 이용!*/
void backtracking(int depth, vector<string> user_id, vector<string> banned_id, set<string> curset)
{
    if (depth == banned_id.size())
    {
        allCases.insert(curset);
        return;
    }

    for (int i = 0; i < user_id.size(); i++)
    {
        if (curset.find(user_id[i]) != curset.end())
        {
            continue;
        }
        if (user_id[i].size() != banned_id[depth].size())
        {

            continue;
        }
        bool isCorrect = true;
        for (int j = 0; j < banned_id[depth].size(); j++)
        {
            if (user_id[i][j] != banned_id[depth][j])
            {
                if (banned_id[depth][j] == '*')
                {
                    continue;
                }
                else
                {
                    isCorrect = false;
                }
            }
        }
        if (isCorrect)
        {
            curset.insert(user_id[i]);
            backtracking(depth + 1, user_id, banned_id, curset);
            // 이걸 꼭 해줘야
            curset.erase(user_id[i]);
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id)
{

    set<string> currset;

    backtracking(0, user_id, banned_id, currset);
    return allCases.size();
}
int main()
{
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "abc1**"};

    int num = solution(user_id, banned_id);
    cout << num << endl;
}