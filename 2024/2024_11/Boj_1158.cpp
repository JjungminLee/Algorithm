#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;

int main()
{
    cin >> n >> k;

    deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push_back(i);
    }
    int idx = 0;
    while (!q.empty())
    {
        idx++;
        if (idx % k == 0)
        {
            int num = q.front();
            v.push_back(num);
            q.pop_front();
        }
        else
        {
            int num = q.front();
            q.pop_front();
            q.push_back(num);
        }
    }
    cout << "<";
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size() - 1)
        {
            cout << v[i] << ", ";
        }
        else
        {
            cout << v[i];
        }
    }
    cout << ">" << endl;
}