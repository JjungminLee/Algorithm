#include <bits/stdc++.h>
using namespace std;

int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string command;
        cin >> command;
        int num;
        cin >> num;
        string input;
        cin >> input;
        string token;
        input = input.substr(1);
        input = input.substr(0, input.size() - 1);
        deque<int> dq;

        istringstream tokenStream(input);

        while (getline(tokenStream, token, ','))
        {
            int val = stoi(token);

            dq.push_back(val);
        }
        bool error = false;
        bool reveresed = false;
        for (int i = 0; i < command.length(); i++)
        {
            if (command[i] == 'R')
            {
                reveresed = !reveresed;
            }
            else if (command[i] == 'D')
            {
                if (dq.empty())
                {
                    error = true;
                    break;
                }
                else
                {
                    if (reveresed)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }
            }
        }
        if (error)
        {
            cout << "error" << "\n";
        }
        else
        {
            if (reveresed)
            {
                reverse(dq.begin(), dq.end());
            }

            cout << "[";
            for (int j = 0; j < dq.size(); j++)
            {
                if (j == dq.size() - 1)
                {
                    cout << dq[j];
                }
                else
                {
                    cout << dq[j] << ",";
                }
            }
            cout << "]\n";
        }
    }
}