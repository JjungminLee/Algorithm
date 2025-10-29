#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    if (v.size() == 1)
    {
        cout << "A" << endl;
        return 0;
    }
    else if (v.size() == 2)
    {
        if (v[0] == v[1])
        {
            cout << v[1] << endl;
        }
        else
        {
            cout << "A" << endl;
        }
        return 0;
    }
    int a, b = 0;
    if (v[1] - v[0] == 0)
    {
        a = 0;
        b = v[0];
    }
    else
    {
        a = (v[2] - v[1]) / (v[1] - v[0]);
        b = v[2] - v[1] * a;
    }
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
    {
        int first = v[i];
        int second = v[i + 1];
        if (first * a + b != second)
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << v[v.size() - 1] * a + b << endl;
    }
    else
    {
        cout << "B" << endl;
    }
}