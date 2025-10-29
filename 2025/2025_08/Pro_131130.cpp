#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int solution(vector<int> cards)
{
    int answer = 0;
    bool visited[101] = {
        false,
    };
    for (int i = 0; i < cards.size(); i++)
    {
        int nextIdx = i;
        int size = 0;
        if (visited[nextIdx])
        {
            continue;
        }
        else
        {
            while (!visited[nextIdx])
            {
                visited[nextIdx] = true;
                nextIdx = cards[nextIdx] - 1;
                size++;
            }
            v.push_back(size);
        }
    }
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (i == j)
                continue;
            answer = max(v[i] * v[j], answer);
        }
    }

    return answer;
}