#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<int> sort_v;
set<int> st;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        st.insert(num);
    }

    for (auto it = st.begin(); it != st.end(); it++)
    {
        sort_v.push_back(*it);
    }

    for (int i = 0; i < n; i++)
    {
        // cout << "v " << sort_v[i] << " ";

        cout << lower_bound(sort_v.begin(), sort_v.end(), v[i]) - sort_v.begin() << " ";
    }
    cout << endl;
}