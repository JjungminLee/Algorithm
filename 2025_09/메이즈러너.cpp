#include <bits/stdc++.h>
using namespace std;

#define MAX 15

int M, N;
int K;
int maps[MAX][MAX];
int shortMaps[MAX][MAX];
int er, ec;
int curTime;
int membersCnt;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int dist;

struct Node {
    int r;
    int c;
};

Node members[MAX];

void input() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i = 1; i <= M; i++) {
        int r, c;
        cin >> r >> c;
        members[i] = {r, c};
        membersCnt++;
    }
    cin >> er >> ec;
}

bool isInRange(int r, int c) {
    return (1 <= r && r <= N && 1 <= c && c <= N);
}

void setShortMap() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            shortMaps[i][j] = abs(i - er) + abs(j - ec);
        }
    }
}

void moving() {
    setShortMap();

    for (int i = 1; i <= M; i++) {
        if (members[i].r == -1) continue; // 이미 탈출

        int cr = members[i].r;
        int cc = members[i].c;

        // 출구 도착
        if (cr == er && cc == ec) {
            members[i].r = -1;
            membersCnt--;
            continue;
        }

        int cdist = shortMaps[cr][cc];
        int bestR = cr, bestC = cc;

        for (int j = 0; j < 4; j++) {
            int nr = cr + dr[j];
            int nc = cc + dc[j];
            if (!isInRange(nr, nc)) continue;
            if (maps[nr][nc] > 0) continue;
            int ndist = shortMaps[nr][nc];
            if (ndist < cdist) {
                cdist = ndist;
                bestR = nr;
                bestC = nc;
            }
        }

        // 이동 적용
        if (bestR != cr || bestC != cc) {
            members[i].r = bestR;
            members[i].c = bestC;
            dist++;
        }

        // 이동 후 출구 도착
        if (members[i].r == er && members[i].c == ec) {
            members[i].r = -1;
            membersCnt--;
        }
    }
}

void rotating() {
    int minLen = N + 1;
    int startR = -1, startC = -1;

    // 1. 정사각형 찾기
    for (int len = 2; len <= N; len++) {
        for (int r = 1; r + len - 1 <= N; r++) {
            for (int c = 1; c + len - 1 <= N; c++) {
                int rr = r + len - 1, cc = c + len - 1;

                // 출구 포함?
                if (!(r <= er && er <= rr && c <= ec && ec <= cc)) continue;

                // 참가자 포함?
                bool hasMember = false;
                for (int i = 1; i <= M; i++) {
                    if (members[i].r == -1) continue;
                    if (r <= members[i].r && members[i].r <= rr &&
                        c <= members[i].c && members[i].c <= cc) {
                        hasMember = true;
                        break;
                    }
                }
                if (!hasMember) continue;

                if (len < minLen) {
                    minLen = len;
                    startR = r;
                    startC = c;
                }
            }
        }
        if (minLen != N + 1) break;
    }

    if (startR == -1) return;

    // 2. 정사각형 회전
    vector<vector<int>> tmp(minLen, vector<int>(minLen));
    for (int i = 0; i < minLen; i++) {
        for (int j = 0; j < minLen; j++) {
            int r = startR + i;
            int c = startC + j;
            tmp[j][minLen - 1 - i] = max(0, maps[r][c] - 1);
        }
    }
    for (int i = 0; i < minLen; i++) {
        for (int j = 0; j < minLen; j++) {
            maps[startR + i][startC + j] = tmp[i][j];
        }
    }

    // 출구 회전
    if (startR <= er && er < startR + minLen && startC <= ec && ec < startC + minLen) {
        int r = er - startR;
        int c = ec - startC;
        int nr = c;
        int nc = minLen - 1 - r;
        er = startR + nr;
        ec = startC + nc;
    }

    // 참가자 회전
    for (int i = 1; i <= M; i++) {
        if (members[i].r == -1) continue;
        if (startR <= members[i].r && members[i].r < startR + minLen &&
            startC <= members[i].c && members[i].c < startC + minLen) {
            int r = members[i].r - startR;
            int c = members[i].c - startC;
            int nr = c;
            int nc = minLen - 1 - r;
            members[i].r = startR + nr;
            members[i].c = startC + nc;
        }
    }
}

bool ifIsEnd() {
    if (curTime >= K) return true;
    if (membersCnt == 0) return true;
    return false;
}

void simulate() {
    while (!ifIsEnd()) {
        moving();
        if (membersCnt == 0) break;
        rotating();
        curTime++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    simulate();
    cout << dist << "\n";      // 총 이동 거리
    cout << er << " " << ec << "\n"; // 최종 출구 좌표
    return 0;
}
