#include <bits/stdc++.h>

using namespace std;
char arr[55][55];
int cx;
int cy;
// e w n s
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int h;
int w;

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    h = park.size();
    w = park[0].size();
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            arr[i][j] = park[i][j];
            if (arr[i][j] == 'S')
            {
                cx = i;
                cy = j;
            }
        }
    }
    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for (int i = 0; i < routes.size(); i++)
    {
        char cmd = routes[i][0];
        int num = stoi(routes[i].substr(2));
        int nx = 0;
        int ny = 0;
        int dirx = 0;
        int diry = 0;
        if (cmd == 'E')
        {
            dirx = dx[0];
            diry = dy[0];
        }
        else if (cmd == 'W')
        {
            dirx = dx[1];
            diry = dy[1];
        }
        else if (cmd == 'N')
        {
            dirx = dx[2];
            diry = dy[2];
        }
        else if (cmd == 'S')
        {
            dirx = dx[3];
            diry = dy[3];
        }
        bool ok = true;
        for (int j = 0; j <= num; j++)
        {
            int nx = cx + dirx * j;
            int ny = cy + diry * j;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
            {
                ok = false;
            }
            if (arr[nx][ny] == 'X')
            {
                ok = false;
            }
        }
        if (ok)
        {
            cx += dirx * num;
            cy += diry * num;
        }
    }
    answer.push_back(cx);
    answer.push_back(cy);
    return answer;
}