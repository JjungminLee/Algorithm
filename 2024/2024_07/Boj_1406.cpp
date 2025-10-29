#include <bits/stdc++.h>
using namespace std;

stack<char> stkL;
stack<char> stkR;

int main()
{
    string str;
    cin >> str;
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        stkL.push(str[i]);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char op;
        cin >> op;
        if (op == 'P')
        {
            char ch;
            cin >> ch;
            stkL.push(ch);
        }
        else if (op == 'L')
        {
            // pop할땐 항상 비어있는거 확인하기!
            if (!stkL.empty())
            {
                char top = stkL.top();
                stkR.push(top);
                stkL.pop();
            }
        }
        else if (op == 'D')
        {
            if (!stkR.empty())
            {
                char top = stkR.top();
                stkL.push(top);
                stkR.pop();
            }
        }
        else if (op == 'B')
        {
            if (!stkL.empty())
            {
                stkL.pop();
            }
        }
    }

    while (!stkL.empty())
    {
        stkR.push(stkL.top());
        stkL.pop();
    }

    while (!stkR.empty())
    {
        ans.append(1, stkR.top());
        stkR.pop();
    }

    cout << ans << endl;

    return 0;
}
