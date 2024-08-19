#include <bits/stdc++.h>
using namespace std;
int t;
/*문제를 잘 읽기!*/
int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int maxPoll = INT_MIN;
        int maxIdx = 0;
        int arr[20];

        for (int i = 0; i < n; i++)
        {

            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxPoll)
            {
                maxPoll = arr[i];
                maxIdx = i;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {

            sum += arr[i];
        }
        int countMax = 0;
        // 최다 득표자가 한명 초과인 경우
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maxPoll)
            {
                countMax++;
            }
        }
        if (countMax > 1)
        {
            cout << "no winner";
        }
        else
        {
            if (maxPoll <= (sum / 2))
            {
                cout << "minority winner " << maxIdx + 1;
            }
            else
            {
                cout << "majority winner " << maxIdx + 1;
            }
        }
        cout << "\n";
    }
}