#include <bits/stdc++.h>
using namespace std;
int arr[9][9];
string a, b;
int num;
int kingX;
int kingY;
int stoneX;
int stoneY;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    cin >> b;
    cin >> num;

    kingX = 8 - (a[1] - '0');
    kingY = a[0] - 65;

    stoneX = 8 - (b[1] - '0');
    stoneY = b[0] - 65;

    for (int i = 0; i < num; i++)
    {
        string input;
        cin >> input;
        if (!strcmp(input.c_str(), "R"))
        {
            if (kingX >= 0 && kingX < 8 && kingY + 1 >= 0 && kingY + 1 < 8)
            {
                if (kingX == stoneX && kingY + 1 == stoneY)
                {
                    if (stoneX >= 0 && stoneX < 8 && stoneY + 1 >= 0 && stoneY + 1 < 8)
                    {
                        stoneY += 1;
                        kingY += 1;
                    }
                }
                else
                {
                    kingY += 1;
                }
            }
            // stone이랑 겹치는지 확인
        }
        else if (!strcmp(input.c_str(), "L"))
        {
            if (kingX >= 0 && kingX < 8 && kingY - 1 >= 0 && kingY - 1 < 8)
            {
                // stone이랑 겹치는지 확인
                if (kingX == stoneX && kingY - 1 == stoneY)
                {
                    if (stoneX >= 0 && stoneX < 8 && stoneY - 1 >= 0 && stoneY - 1 < 8)
                    {
                        stoneY -= 1;
                        kingY -= 1;
                    }
                }
                else
                {
                    kingY -= 1;
                }
            }
        }
        else if (!strcmp(input.c_str(), "B"))
        {
            if (kingX + 1 >= 0 && kingX + 1 < 8 && kingY >= 0 && kingY < 8)
            {
                // stone이랑 겹치는지 확인
                if (kingX + 1 == stoneX && kingY == stoneY)
                {
                    if (stoneX + 1 >= 0 && stoneX + 1 < 8 && stoneY >= 0 && stoneY < 8)
                    {
                        stoneX += 1;
                        kingX += 1;
                    }
                }
                else
                {
                    kingX += 1;
                }
            }
        }
        else if (!strcmp(input.c_str(), "T"))
        {
            if (kingX - 1 >= 0 && kingX - 1 < 8 && kingY >= 0 && kingY < 8)
            {
                // stone이랑 겹치는지 확인
                if (kingX - 1 == stoneX && kingY == stoneY)
                {
                    if (stoneX - 1 >= 0 && stoneX - 1 < 8 && stoneY >= 0 && stoneY < 8)
                    {
                        stoneX -= 1;
                        kingX -= 1;
                    }
                }
                else
                {
                    kingX -= 1;
                }
            }
        }
        else if (!strcmp(input.c_str(), "RT"))
        {
            if (kingX - 1 >= 0 && kingX - 1 < 8 && kingY + 1 >= 0 && kingY + 1 < 8)
            {
                // stone이랑 겹치는지 확인
                if (kingX - 1 == stoneX && kingY + 1 == stoneY)
                {
                    if (stoneX - 1 >= 0 && stoneX - 1 < 8 && stoneY + 1 >= 0 && stoneY + 1 < 8)
                    {
                        stoneX -= 1;
                        stoneY += 1;
                        kingX -= 1;
                        kingY += 1;
                    }
                }
                else
                {
                    kingX -= 1;
                    kingY += 1;
                }
            }
        }
        else if (!strcmp(input.c_str(), "LT"))
        {
            if (kingX - 1 >= 0 && kingX - 1 < 8 && kingY - 1 >= 0 && kingY - 1 < 8)
            {
                // stone이랑 겹치는지 확인
                if (kingX - 1 == stoneX && kingY - 1 == stoneY)
                {
                    if (stoneX - 1 >= 0 && stoneX - 1 < 8 && stoneY - 1 >= 0 && stoneY - 1 < 8)
                    {
                        stoneX -= 1;
                        stoneY -= 1;
                        kingX -= 1;
                        kingY -= 1;
                    }
                }
                else
                {
                    kingX -= 1;
                    kingY -= 1;
                }
            }
        }

        else if (!strcmp(input.c_str(), "RB"))
        {
            if (kingX + 1 >= 0 && kingX + 1 < 8 && kingY + 1 >= 0 && kingY + 1 < 8)
            {

                // stone이랑 겹치는지 확인
                if (kingX + 1 == stoneX && kingY + 1 == stoneY)
                {
                    if (stoneX + 1 >= 0 && stoneX + 1 < 8 && stoneY + 1 >= 0 && stoneY + 1 < 8)
                    {
                        stoneX += 1;
                        stoneY += 1;
                        kingX += 1;
                        kingY += 1;
                    }
                }
                else
                {
                    kingX += 1;
                    kingY += 1;
                }
            }
        }
        else if (!strcmp(input.c_str(), "LB"))
        {

            if (kingX + 1 >= 0 && kingX + 1 < 8 && kingY - 1 >= 0 && kingY - 1 < 8)
            {
                // stone이랑 겹치는지 확인
                if (kingX + 1 == stoneX && kingY - 1 == stoneY)
                {
                    if (stoneX + 1 >= 0 && stoneX + 1 < 8 && stoneY - 1 >= 0 && stoneY - 1 < 8)
                    {
                        stoneX += 1;
                        stoneY -= 1;
                        kingX += 1;
                        kingY -= 1;
                    }
                }
                else
                {
                    kingX += 1;
                    kingY -= 1;
                }
            }
        }
    }

    cout << char(kingY + 65) << 8 - kingX << endl;
    cout << char(stoneY + 65) << 8 - stoneX << endl;
}