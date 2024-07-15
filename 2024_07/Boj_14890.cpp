#include <iostream>
#include <cmath>
using namespace std;
int road1[101][101];
int road2[101][101];
int n, l;
int result = 0;
void PassCnt(int road[][101])
{
    // 가로 확인
    for (int i = 0; i < n; i++)
    {
        bool slope[101] = {0}; // 경사로 여부
        bool possible = true;  // 가능한 길인지 확인
        for (int h = 0; h < n - 1; h++)
        {
            if (abs(road[i][h] - road[i][h + 1]) > 1)
            {
                // 1. 높이차가 1보다 크면 불가능한 길
                possible = false;
                break;
            }

            // 2. 경사로를 위에서 아래로 설치 할 때
            if (road[i][h] == road[i][h + 1] + 1)
            {
                int cur_hight = road[i][h + 1];
                for (int k = h + 2; k < h + 1 + l; k++)
                {
                    if (k >= n || road[i][k] != cur_hight)
                    {
                        // L만큼의 여유가 있는지 확인
                        possible = false;
                        break;
                    }
                }
                if (possible)
                {
                    // 경사로 설치하면 설치했다고 표시
                    slope[h + l] = true;
                }
                else
                {
                    break;
                }
            }

            // 3. 경사로를 아래에서 위로 설치 할 때
            if (road[i][h] == road[i][h + 1] - 1)
            {
                int cur_hight = road[i][h];
                for (int k = h; k > h - l; k--)
                {
                    if (k < 0 || road[i][k] != cur_hight || slope[k])
                    {
                        // L만큼의 여유와 경사로 설치 여부 확인
                        possible = false;
                        break;
                    }
                }
                if (!possible)
                {
                    break;
                }
            }
        }
        if (possible)
        {
            result++; // 길이면 카운트
        }
    }
}

int main()
{
    cin >> n >> l; // 입력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> road1[i][j];        // 가로로 가는 길 확인
            road2[j][i] = road1[i][j]; // 세로로 가는 길 확인
        }
    }
    PassCnt(road1); // 가로로 가는 길 개수
    PassCnt(road2); // 세로로 가는 길 개수
    cout << result << endl;
