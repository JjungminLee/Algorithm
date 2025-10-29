#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> crain;
vector<int> boxes;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        crain.push_back(num);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        boxes.push_back(num);
    }
    sort(boxes.begin(), boxes.end(), [](int a, int b)
         { return a > b; });
    sort(crain.begin(), crain.end(), [](int a, int b)
         { return a > b; });
    if (boxes[0] > crain[0])
    {
        cout << -1 << endl;
    }
    else
    {

        int time = 0;
        while (!boxes.empty())
        {
            int boxIdx = 0;
            // 매 루프를 돌때마다 n개만큼씩은 꼭 검사해야함!
            for (int i = 0; i < n; i++)
            {
                if (boxIdx >= boxes.size())
                {
                    break;
                }
                if (boxes[boxIdx] <= crain[i])
                {
                    boxes.erase(boxes.begin() + boxIdx);
                }
                else
                {
                    boxIdx++;
                }
            }
            time++;
        }
        cout << time << endl;
    }
}