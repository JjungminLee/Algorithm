#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    // 벡터 초기화 꼭!
    vector<int> height(w);
    vector<int> leftv(w);
    vector<int> rightv(w);

    for (int i = 0; i < w; i++)
    {
        cin >> height[i];
    }
    leftv[0] = height[0];
    // 왼쪽벽
    for (int i = 1; i < w; i++)
    {
        leftv[i] = max(leftv[i - 1], height[i]);
    }

    rightv[w - 1] = height[w - 1];
    // 오른쪽 벽
    for (int i = w - 2; i >= 0; i--)
    {
        rightv[i] = max(rightv[i + 1], height[i]);
    }

    int cnt = 0;
    for (int i = 0; i < w; i++)
    {
        int level = min(rightv[i], leftv[i]);
        if (height[i] < level)
        {
            cnt += (level - height[i]);
        }
    }
    cout << cnt << endl;
}