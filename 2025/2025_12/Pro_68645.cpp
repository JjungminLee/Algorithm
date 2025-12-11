#include <bits/stdc++.h>

using namespace std;
int last = 0;
int arr[1005][1005];
int sx, sy;

vector<int> solution(int n)
{
    vector<int> answer;
    last = ((1 + n) * n) / 2;
    int len = n;
    sx = 0;
    sy = 0;
    int curNum = 1;
    while (len > 1)
    {
        int x = sx;
        int y = sy;

        // ㄴ자로 채우기
        // |로 채우기
        // cout<<"len "<<len<<"sx "<<sx<<"sy "<<sy<<endl;
        for (int i = 0; i < len; i++)
        {
            arr[x][y] = curNum++;
            x++;
        }
        x--;
        // -로 채우기
        for (int i = 1; i < len; i++)
        {
            arr[x][y + i] = curNum++;
        }
        y = y + (len - 1);

        // 대각선으로 len-2칸
        for (int i = 1; i < len - 1; i++)
        {
            arr[x - i][y - i] = curNum++;
        }

        len -= 3;
        sx += 2;
        sy += 1;
    }

    if (len == 1)
    {
        arr[sx][sy] = curNum;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                answer.push_back(arr[i][j]);
            }
        }
    }
    return answer;
}