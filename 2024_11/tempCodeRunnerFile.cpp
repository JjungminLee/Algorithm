#include <bits/stdc++.h>
using namespace std;
int arr[501][501];
// {숫자, 인덱스 위치}
vector<pair<int, int>> v;
int h, w;

// 벽은 2, 물은 1로 채워짐
int main()
{
    cin >> h >> w;
    for (int i = 0; i < w; i++)
    {
        int num;
        cin >> num;
        v.push_back({num, i});
        // w가 4라면 j=4부터 1까지 채워짐
        for (int k = h - num; k < h; k++)
        {

            arr[k][i] = 2;
        }
    }

    reverse(v.begin(), v.end());
    if (v.size() == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    // 첫 번째 원소 기준 내림차순 정렬 -> 제일 큰애 찾기 위함
    vector<pair<int, int>> v_first = v; // 원본 벡터 복사
    sort(v_first.begin(), v_first.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.first > b.first; // 첫 번째 원소 기준 내림차순
         });

    int targetIdx = v_first[0].second;
    // 두 번째 원소 기준 오름차순 정렬 -> 위치 기준으로 오름차순
    vector<pair<int, int>> v_second = v;
    sort(v_second.begin(), v_second.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });
    int maxIdx = 0;
    int maxNum = 0;
    for (int i = 0; i < targetIdx; i++)
    {
        if (maxNum < v_second[i].first)
        {
            maxNum = v_second[i].first;
            maxIdx = v_second[i].second;
        }
    }
    int cnt = 0;
    for (int j = h - maxNum; j < h; j++)
    {
        for (int i = maxIdx; i < targetIdx; i++)
        {
            if (arr[j][i] != 2)
            {
                arr[j][i] = 1;
                cnt += 1;
            }
        }
    }

    int maxIdx2 = 0;
    int maxNum2 = 0;
    for (int i = targetIdx + 1; i < w; i++)
    {
        if (maxNum2 < v_second[i].first)
        {
            maxNum2 = v_second[i].first;
            maxIdx2 = v_second[i].second;
        }
    }

    for (int i = targetIdx + 1; i < w; i++)
    {
        for (int j = h - maxNum2; j < h; j++)
        {
            if (arr[j][i] != 2)
            {
                arr[j][i] = 1;

                cnt += 1;
            }
        }
    }

    cout << cnt << endl;
}