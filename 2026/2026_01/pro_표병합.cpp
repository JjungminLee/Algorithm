#include <bits/stdc++.h>

using namespace std;

#define maxNum 55 * 55

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
string arr[maxNum];
int parents[maxNum];
vector<string> answer;

int findIdx(int r, int c)
{
    return (r - 1) * 55 + c;
}

int findParent(int x)
{
    if (parents[x] == x)
    {
        return x;
    }
    return parents[x] = findParent(parents[x]);
}

void unions(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a == b)
        return;
    parents[b] = a;
}

vector<string> solution(vector<string> commands)
{

    for (int i = 1; i <= 50; i++)
    {
        for (int j = 1; j <= 50; j++)
        {
            int id = findIdx(i, j);
            parents[id] = id;
            arr[id] = "";
        }
    }
    for (string str : commands)
    {
        vector<string> v;
        string cmd = "";

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == ' ')
            {
                v.push_back(cmd);
                cmd = "";
            }
            else
            {
                cmd += str[j];
            }
        }

        if (!cmd.empty())
        {
            v.push_back(cmd);
        }

        if (v[0] == "UPDATE")
        {

            if (v.size() == 4)
            {
                int r = stoi(v[1]);
                int c = stoi(v[2]);
                string val = v[3];
                int id = findIdx(r, c);
                int root = findParent(id);
                arr[root] = val;
            }
            else if (v.size() == 3)
            {
                string val1 = v[1];
                string val2 = v[2];
                for (int i = 1; i <= 50; i++)
                {
                    for (int j = 1; j <= 50; j++)
                    {
                        int id = findIdx(i, j);
                        int root = findParent(id);
                        if (arr[root] == val1)
                        {
                            arr[root] = val2;
                        }
                    }
                }
            }
        }
        else if (v[0] == "MERGE")
        {
            int r1 = stoi(v[1]);
            int c1 = stoi(v[2]);
            int r2 = stoi(v[3]);
            int c2 = stoi(v[4]);
            int idx1 = findIdx(r1, c1);
            int idx2 = findIdx(r2, c2);
            int root1 = findParent(idx1);
            int root2 = findParent(idx2);

            if (root1 == root2)
            {
                // 이미 같은 셀
                continue;
            }

            string newVal = arr[root1];
            if (newVal == "")
            {
                newVal = arr[root2];
            }

            unions(root1, root2);
            int root = findParent(root1);
            arr[root] = newVal;
        }
        else if (v[0] == "UNMERGE")
        {
            int r = stoi(v[1]);
            int c = stoi(v[2]);
            int idx = findIdx(r, c);
            int root = findParent(idx);
            string val = arr[root];
            vector<int> v;

            for (int i = 1; i <= 50; i++)
            {
                for (int j = 1; j <= 50; j++)
                {
                    int id = findIdx(i, j);
                    if (findParent(id) == root)
                    {
                        v.push_back(id);
                    }
                }
            }
            for (int num : v)
            {
                arr[num] = "";
                parents[num] = num;
            }
            arr[idx] = val;
        }
        else if (v[0] == "PRINT")
        {
            int r = stoi(v[1]);
            int c = stoi(v[2]);
            int idx = findIdx(r, c);
            int root = findParent(idx);
            if (arr[root] == "")
            {
                answer.push_back("EMPTY");
            }
            else
            {
                answer.push_back(arr[root]);
            }
        }
    }
    return answer;
}