#include <bits/stdc++.h>

using namespace std;

struct Robot
{

    int curx, cury;
    int curIdx;
    vector<int> route;
    bool finished;
};

vector<vector<int>> graph;
vector<Robot> robots;

void moveRobots(vector<vector<int>> routes, vector<vector<int>> points)
{
    for (auto &robot : robots)
    {
        int curx = robot.curx;
        int cury = robot.cury;
        int curIdx = robot.curIdx;

        if (robot.finished)
            continue;

        int nextIdx = 0;
        if (curIdx + 1 < robot.route.size())
        {
            nextIdx = robot.route[curIdx + 1];
        }
        int nextx = points[nextIdx - 1][0];
        int nexty = points[nextIdx - 1][1];

        if (curx != nextx)
        {
            curx += curx > nextx ? -1 : 1;
        }
        else if (cury != nexty)
        {
            cury += cury > nexty ? -1 : 1;
        }
        robot.curx = curx;
        robot.cury = cury;

        if (curx == nextx && cury == nexty)
        {
            robot.curIdx++;
        }
    }
}

int countCollision()
{
    map<pair<int, int>, int> mp;
    for (int i = 0; i < robots.size(); i++)
    {
        if (!robots[i].finished)
        {
            mp[{robots[i].curx, robots[i].cury}]++;
        }
    }
    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > 1)
        {
            cnt++;
        }
    }
    return cnt;
}

bool allFinished()
{
    for (int i = 0; i < robots.size(); i++)
    {
        if (!robots[i].finished)
        {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    int answer = 0;
    for (int i = 0; i < routes.size(); i++)
    {
        Robot r;
        r.curx = points[routes[i][0] - 1][0];
        r.cury = points[routes[i][0] - 1][1];
        r.curIdx = 0;
        r.finished = false;
        r.route = routes[i];
        robots.push_back(r);
    }
    answer += countCollision();
    while (!allFinished())
    {
        moveRobots(routes, points);
        answer += countCollision();

        // 현재 turn에서 도착한 애들 집계 -> move에서 집계하면 현재 turn에서 도착한 애들 조차
        // 다 끝났다고 판단하여 countCollision에서 집계를 안함!
        for (int i = 0; i < robots.size(); i++)
        {
            if (!robots[i].finished && robots[i].curIdx == robots[i].route.size() - 1)
            {
                robots[i].finished = true;
            }
        }
    }
    return answer;
}