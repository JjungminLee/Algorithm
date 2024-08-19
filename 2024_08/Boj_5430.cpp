#include <bits/stdc++.h>
using namespace std;
int t;

/*
T: 1

P: D

n: 0

arr: []


T: 1

P: R

n: 0

arr: []
*/
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
        deque<int> dq;
        string token;
        input = input.substr(1);
        input = input.substr(0, input.size() - 1);

        istringstream tokenStream(input);

        while (getline(tokenStream, token, ','))
        {
            int val = stoi(token);

            dq.push_back(val);
        }

        bool error = false;
        bool reversed = false;

        for (int i = 0; i < command.length(); i++)
        {
            if (command[i] == 'R')
            {
                reversed = !reversed;
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
                    if (reversed)
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

            cout << "[";
            if (reversed)
                reverse(dq.begin(), dq.end()); // 최종 결과를 뒤집어야 할 경우에만 뒤집기
            for (int j = 0; j < dq.size(); j++)
            {
                cout << dq[j];
                if (j != dq.size() - 1)
                    cout << ",";
            }
            cout << "]\n";
        }
    }
}