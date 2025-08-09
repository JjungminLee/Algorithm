#include <bits/stdc++.h>
using namespace std;

int n;
int k;
char arr[20001];
bool visited[20001];
int cnt;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'P')
        {
            int start = max(0, i - k);
            int end = i + k;
            for (int j = start; j <= end; j++)
            {
                if (arr[j] == 'H' && !visited[j])
                {
                    visited[j] = true;
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << "\n";
}