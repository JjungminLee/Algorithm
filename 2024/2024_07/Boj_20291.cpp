#include <bits/stdc++.h>
using namespace std;

int n;
string arr[50001];
unordered_map<string, int> maps;
/*
빈도를 셀때는 vector보다는 unordered map이 적당하다! (O(1))
키-값 쌍을 평균적으로 O(1) 시간에 삽입 및 검색할 수 있어, 빈도수 계산 시 벡터보다 훨씬 효율적
어차피 벡터로 만들어도 pair쓸거니까 ! (vector의 경우 O(n^2))

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int len = arr[i].length();
        string target = "";
        int idx = 0;
        for (int j = 0; j < len; j++)
        {
            if (arr[i][j] == '.')
            {
                idx = j + 1;
                break;
            }
        }
        while (idx < len)
        {
            target += arr[i][idx];
            idx++;
        }
        maps[target]++;
    }
    vector<pair<string, int>> v(maps.begin(), maps.end());
    sort(v.begin(), v.end());
    for (auto &p : v)
    {
        cout << p.first << " " << p.second << "\n";
    }
}