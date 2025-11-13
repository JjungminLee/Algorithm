#include <bits/stdc++.h>

using namespace std;
bool visited[55];

// 무조건 맨앞부터 순차적으로 가는게 아니라 현재 시점의 문자열 기준으로 차이가 1인애들을 words배열에서 찾아서 가는거
int solution(string begin, string target, vector<string> words)
{
    int answer = INT_MAX;
    // 인덱스, 몇단계 거친건지
    queue<pair<string, pair<int, int>>> q;

    q.push({begin, {-1, 0}});

    while (!q.empty())
    {
        auto cur = q.front();
        string str = cur.first;
        int idx = cur.second.first;
        int stage = cur.second.second;

        cout << "str " << str << "idx " << idx << "stage " << stage << endl;

        if (str == target)
        {
            answer = min(stage, answer);
        }

        q.pop();
        for (int i = 0; i < words.size(); i++)
        {
            string cmp = words[i];
            int diff = 0;
            for (int j = 0; j < cmp.size(); j++)
            {
                if (cmp[j] != str[j])
                {
                    diff++;
                }
            }
            if (diff == 1 && !visited[i])
            {
                visited[i] = true;
                q.push({cmp, {i, stage + 1}});
            }
        }
    }

    if (answer != INT_MAX)
    {
        return answer;
    }
    return 0;
}