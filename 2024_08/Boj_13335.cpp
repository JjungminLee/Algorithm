#include<bits/stdc++.h>
using namespace std;

int n, w, l;
vector<int> v;
deque<int> dq;
int ans;

int main() {
    cin >> n >> w >> l;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    dq.push_back(v[0]);
    int sum = v[0];
    int idx = 1;
    ans = 0;

    while (1) {
        ans++;
        if (idx >= n && sum == 0) {
            break;
        }

        if (dq.size() == w) {
            int num = dq.front();
            sum -= num;
            dq.pop_front();
        }

        // 최대하중을 넘기지 않는 경우
        if (idx < n && sum + v[idx] <= l) {
            dq.push_back(v[idx]);
            sum += v[idx];
            idx++;
        } else {
            // 최대하중을 넘기는 경우 또는 더 이상 추가할 차가 없을 때
            dq.push_back(0);
        }
    }

    cout << ans << endl;
}
