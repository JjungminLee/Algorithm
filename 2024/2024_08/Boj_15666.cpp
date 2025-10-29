#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> arr;
unordered_set<int>
    set_arr;
vector<vector<int>> results;

void dfs(int num, int idx, vector<int> v)
{

    if (num == m)
    {
        results.push_back(v);

        return;
    }
    // 시작을 idx이후부터 하게 하기 위함 (중복되는 수열이 나오지 않게!)
    for (int i = idx; i < arr.size(); i++)
    {
        v.push_back(arr[i]);
        dfs(num + 1, i, v);
        v.pop_back();
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        set_arr.insert(num);
    }

    arr.assign(set_arr.begin(), set_arr.end()); // set의 모든 원소를 vector에 복사
    sort(arr.begin(), arr.end());               // vector를 정렬

    vector<int> v = vector<int>();
    dfs(0, 0, v);
    sort(results.begin(), results.end());
    for (int i = 0; i < results.size(); i++)
    {
        for (int j = 0; j < results[i].size(); j++)
        {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
}