#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // dp는 LIS의 길이와 그 길이를 만족시키는 마지막 원소의 값을 관리하며, 주로 LIS의 최대 길이를 계산하는 데 초점
    // lis_index는 dp 배열의 각 원소가 실제 수열에서 어디에 위치하는지를 추적, 역추적 시 유용
    vector<int> arr(n), dp, parent(n, -1);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> lis_index;

    for (int i = 0; i < n; ++i)
    {
        // 이진 탐색
        // dp 벡터에서 arr[i]보다 크거나 같은 첫 번째 원소 찾기
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        // 인덱스 계산 (dp 내에서 어디에 저장된건지)
        int idx = it - dp.begin();
        // 맨 뒤면 그냥 맨 뒤에 넣으면 됨
        if (it == dp.end())
        {
            dp.push_back(arr[i]);
            lis_index.push_back(i);
        }
        else
        {
            // 그렇지 않으면 새로운 자리에
            *it = arr[i];
            lis_index[idx] = i;
        }

        // prev 인덱스 업데이트
        // parent에는 lis_index에 들어오기 직전의 원소가 들어간다.
        //  LIS를 정확하게 복원하기 위함.
        if (idx > 0)
        {
            parent[i] = lis_index[idx - 1];
        }
    }

    // LIS 추적
    int lis_end = lis_index.back();

    vector<int> lis;
    for (int i = lis_end; i != -1; i = parent[i])
    {
        lis.push_back(arr[i]);
    }
    reverse(lis.begin(), lis.end()); // 역순으로 추가했으므로 정방향으로 뒤집기

    cout << dp.size() << endl;
    for (int num : lis)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
