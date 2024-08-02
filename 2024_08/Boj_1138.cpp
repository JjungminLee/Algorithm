#include <bits/stdc++.h>
using namespace std;

int arr[11];
int ans[11];
// ans가 빈공간일때 어떻게 배치하냐가 핵심인 문제
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        // ans 배열에 들어갈 숫자
        int num = i + 1;
        // num이 ans배열에 배치돠기 위해 앞에서 부터 필요한 공백
        int spaces = arr[i];
        for (int j = 0; j < n; j++)
        {
            // 비어있는 공간에만 넣는다. 그래야 내 앞에 키큰 사람의 수 만족하기 가능 (이걸 써야 swap을 안할 수 있음)
            if (ans[j] == 0)
            {
                if (spaces == 0)
                {
                    ans[j] = num;
                }
                spaces--;
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
