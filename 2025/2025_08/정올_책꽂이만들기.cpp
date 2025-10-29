#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
int main()
{
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }
    while (pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second);
        ans += (first + second);
    }
    cout << ans << "\n";
}