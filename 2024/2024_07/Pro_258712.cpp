#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts)
{
    vector<tuple<string, int, int>> v; // 이름 주 받 (지수 계산)
    vector<int> ans(friends.size());

    for (int i = 0; i < friends.size(); i++)
    {
        v.push_back({friends[i], 0, 0});
    }
    for (int i = 0; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        string word;
        vector<string> input;
        while (ss >> word)
        {
            input.push_back(word);
        }
        for (int j = 0; j < v.size(); j++)
        {

            if (get<0>(v[j]) == input[0])
            {
                get<1>(v[j])++;
            }
            else if (get<0>(v[j]) == input[1])
            {
                get<2>(v[j])++;
            }
        }
    }

    for (int i = 0; i < friends.size() - 1; i++)
    {
        for (int j = 1; j < friends.size(); j++)
        {
            if (i == j || i > j)
            {
                continue;
            }
            int i_give = 0;

            int j_give = 0;

            for (int k = 0; k < gifts.size(); k++)
            {
                stringstream ss(gifts[k]);
                string word;
                vector<string> input;
                while (ss >> word)
                {
                    input.push_back(word);
                }
                if (input[0] == friends[i] && input[1] == friends[j])
                {
                    i_give++;
                }

                else if (input[0] == friends[j] && input[1] == friends[i])
                {
                    j_give++;
                }
            }

            if (i_give > j_give)
            {
                ans[i]++;
            }
            else if (i_give < j_give)
            {
                ans[j]++;
            }
            else
            {

                int i_point = 0;
                int j_point = 0;
                i_point += (get<1>(v[i]) - get<2>(v[i]));
                j_point += (get<1>(v[j]) - get<2>(v[j]));

                if (i_point > j_point)
                {
                    ans[i]++;
                }
                else if (i_point < j_point)
                {
                    ans[j]++;
                }
            }
        }
    }
    int answer = 0;

    sort(ans.begin(), ans.end(), greater<int>());
    answer = ans[0];
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return answer;
}
int main()
{
    vector<string> friends = {"joy", "brad", "alessandro", "conan", "david"};
    vector<string>
        gifts = {"alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"};
    int num = solution(friends, gifts);
    cout << num << endl;
}