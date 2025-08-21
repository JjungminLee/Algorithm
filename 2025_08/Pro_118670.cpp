#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations)
{

    int r = rc.size();
    int c = rc[0].size();
    vector<vector<int>> answer(r, vector<int>(c));

    deque<int> left, right;
    deque<deque<int>> mid(r);

    for (int i = 0; i < r; i++)
    {
        left.push_back(rc[i][0]);
        right.push_back(rc[i][c - 1]);
        if (c > 2)
        { // 열이 3개 이상이면
            mid[i] = deque<int>(rc[i].begin() + 1, rc[i].end() - 1);
        }
    }
    for (string str : operations)
    {
        if (str == "Rotate")
        {
            if (c < 2)
            {
                continue;
            }
            else if (c == 2)
            {
                int leftTop = left.front();
                left.pop_front();
                right.push_front(leftTop);

                int rightBelow = right.back();
                right.pop_back();
                left.push_back(rightBelow);
            }
            else
            {
                // left 맨 위=> mid 윗항 맨 앞
                int leftTop = left.front();
                left.pop_front();
                mid[0].push_front(leftTop);

                // mid 윗 항 맨뒤 => right 맨 위
                int mid1 = mid[0].back();
                mid[0].pop_back();
                right.push_front(mid1);

                // right 맨 아래 => mid 아래항 맨 뒤
                int rightBelow = right.back();
                right.pop_back();
                mid[r - 1].push_back(rightBelow);

                // mid 아래 항 맨 앞 => left 맨뒤
                int mid2 = mid[r - 1].front();
                mid[r - 1].pop_front();
                left.push_back(mid2);
            }
        }
        else if (str == "ShiftRow")
        {
            left.push_front(left.back());
            left.pop_back();

            right.push_front(right.back());
            right.pop_back();

            if (c > 2)
            {
                mid.push_front(move(mid.back()));
                mid.pop_back();
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        answer[i][0] = left[i];
        int idx = 1;
        if (c > 2)
        {
            for (int num : mid[i])
            {
                answer[i][idx] = num;
                idx++;
            }
        }
        answer[i][c - 1] = right[i];
    }
    return answer;
}