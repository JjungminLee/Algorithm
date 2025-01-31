#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> crains;
vector<long long> boxes;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        crains.push_back(num);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        long long num;
        cin >> num;
        boxes.push_back(num);
    }
    sort(crains.begin(), crains.end(), [](long long a, long long b)
         { return a > b; });
    sort(boxes.begin(), boxes.end(), [](long long a, long long b)
         { return a > b; });

    if (boxes[0] > crains[0])
    {
        cout << -1 << endl;
    }
    else
    {
        int time = 0;
        list<long long> boxList(boxes.begin(), boxes.end());
        while (!boxList.empty())
        {
            auto it = boxList.begin();
            for (int i = 0; i < n && it != boxList.end();)
            {
                if (crains[i] >= *it)
                {
                    i++;
                    it = boxList.erase(it);
                }
                else
                {
                    it++;
                }
            }
            time++;
        }
        cout << time << endl;
    }
}
