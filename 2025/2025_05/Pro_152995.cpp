#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int first, second, idx;
};
vector<Node> v;

bool comparators(Node a, Node b)
{
    if (a.first + a.second == b.first + b.second)
    {
        return a.idx < b.idx;
    }
    return a.first + a.second > b.first + b.second;
}

int solution(vector<vector<int>> scores)
{
    int answer = 0;
    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1])
        {
            return -1;
        }
    }

    for (int i = 0; i < scores.size(); i++)
    {
        v.push_back({scores[i][0], scores[i][1], i});
    }

    sort(v.begin(), v.end(), comparators);

    for (int i = 0; i < v.size(); i++)
    {
        Node node = v[i];

        if (node.idx == 0)
        {
            // 인센 못받는 사람 처리
            int cnt = i + 1;
            for (int j = 0; j <= i; j++)
            {
                bool flag = true;
                for (int k = 0; k < v.size(); k++)
                {
                    if (v[j].first < v[k].first && v[j].second < v[k].second)
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                {
                    cnt--;
                }
            }
            answer = cnt;
        }
    }

    return answer;
}