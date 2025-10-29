#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001];

int m;

deque<int> dq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 큐 -> 뒤에 삽입, 앞에 제거, 스택 -> 뒤에 삽입, 뒤에 제거 (아무일도 안일어남)
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (arr[i] == 0)
        {

            dq.push_front(x);
        }
    }
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        dq.push_back(input);
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
}
