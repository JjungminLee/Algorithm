#include <bits/stdc++.h>
using namespace std;
int t;

int check(vector<int> v, vector<int> v2)
{
    return v == v2;
}
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> v = vector<int>(n + 1);
        vector<int> target = vector<int>(n + 1);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
            target[j] = j + 1;
        }
        v[n] = 510;
        target[n] = 510;
        int cnt = 0;

        vector<int> moves;
        while (1)
        {
            cnt++;

            if (check(v, target))
            {
                break;
            }
            else
            {
                int posIdx = find(v.begin(), v.end(), 510) - v.begin(); // -> find말고 v[a]=i 이런식으로 저장해두기!
                // for (int i = 0; i < v.size(); i++)
                // {
                //     cout << v[i] << " ";
                // }

                if (cnt > 1)
                {
                    moves.push_back(posIdx + 1);
                }

                if (v[0] == 510)
                {
                    int minIdx = 0;
                    int minNum = INT_MAX;
                    for (int i = 1; i <= n; i++)
                    {
                        if (minNum > v[i])
                        {
                            minIdx = i;
                            minNum = v[i];
                        }
                    }
                    int temp = v[minIdx];
                    v[minIdx] = 510;
                    v[posIdx] = temp;
                    posIdx = minIdx;
                }
                else if (v[0] != 1)
                {

                    int maxIdx = 0;
                    int maxNum = INT_MIN;
                    for (int i = 0; i < posIdx; i++)
                    {
                        if (maxNum < v[i])
                        {
                            maxIdx = i;
                            maxNum = v[i];
                        }
                    }
                    int temp = v[maxIdx];
                    v[maxIdx] = 510;
                    v[posIdx] = temp;
                    posIdx = maxIdx;
                }
                else if (v[0] == 1)
                {
                    int minNum = INT_MAX;
                    int minIdx = 0;
                    for (int i = posIdx + 1; i <= n; i++)
                    {
                        if (minNum > v[i])
                        {
                            minIdx = i;
                            minNum = v[i];
                        }
                    }
                    int temp = v[minIdx];
                    v[minIdx] = 510;
                    v[posIdx] = temp;
                    posIdx = minIdx;
                }
            }
        }

        if (moves.size() > 0)
        {
            cout << moves.size() + 1 << endl;
            for (int j = 0; j < moves.size(); j++)
            {
                cout << moves[j] << " ";
            }
            cout << n + 1 << endl;
        }
        else
        {
            cout << moves.size() << endl;
            cout << endl;
        }
    }
}