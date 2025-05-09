#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        b.push_back(num);
    }
    int answer = INT_MAX;
    sort(a.begin(), a.end());

    do
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {

            temp += (a[i] * b[i]);
        }
        cout << endl;

        answer = min(answer, temp);

    } while (next_permutation(a.begin(), a.end()));
    cout << answer << endl;
}