#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int idx[50];
int copy[50];
int init_state[50];
int suffle[50];
int num;

bool isSorted()
{
    for (int i = 0; i < num; i++)
        if (idx[i] != (i % 3))
            return false;

    return true;
}

void solve()
{
    int count = 0;
    while (isSorted() == false)
    {
        count++;

        // 카드 섞기
        for (int i = 0; i < num; i++)
            ::copy[i] = idx[i];

        for (int i = 0; i < num; i++)
            idx[suffle[i]] = ::copy[i];

        // 카드가 섞기 전 맨 처음 상태인지 확인
        for (int i = 0; i < num; i++)
        {
            if (init_state[i] != idx[i])
                break;

            if (i == num - 1)
            {
                // 싸이클이 발생, 아무리 섞어도 종료 조건을 충족하지 못함
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> idx[i];
        init_state[i] = idx[i];
    }

    for (int i = 0; i < num; i++)
        cin >> suffle[i];

    solve();
    return 0;
}