#include <bits/stdc++.h>
using namespace std;

int n;
int arr[20]; // 배열 크기는 수식의 길이에 맞춰 설정
vector<tuple<int, char, int>> v;
int ans = INT_MIN;

// 주어진 수식을 연산할 수 있게 변환하는 함수
void make_comb() {
    for (int i = 0; i < n - 2; i += 2) {
        int first = arr[i];
        char oper = (char)arr[i + 1];
        int second = arr[i + 2];
        v.push_back({first, oper, second});
    }
}

// 연산 함수
int calculate(int a, char oper, int b) {
    if (oper == '+') return a + b;
    if (oper == '-') return a - b;
    if (oper == '*') return a * b;
    return 0;
}

// 수식 계산 함수
void operate(int cnt, int current, vector<bool> &visited) {
    if (cnt == 0) {
        int operateAns = arr[0];
        for (int i = 1; i < n; i += 2) {
            char oper = (char)arr[i];
            int second = arr[i + 1];
            operateAns = calculate(operateAns, oper, second);
        }
        ans = max(ans, operateAns);
        return;
    }

    if (cnt == current) {
        vector<int> nums;
        vector<char> ops;
        int i = 0;

        while (i < v.size()) {
            int first, second;
            char oper;
            tie(first, oper, second) = v[i];

            if (visited[i]) {
                first = calculate(first, oper, second);
                if (i + 1 < v.size()) {
                    i++;
                    tie(ignore, oper, second) = v[i];
                }
            }
            nums.push_back(first);
            if (i < v.size()) ops.push_back(oper);
            i++;
        }

        int result = nums[0];
        for (int i = 0; i < ops.size(); i++) {
            result = calculate(result, ops[i], nums[i + 1]);
        }

        ans = max(ans, result);
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!visited[i] && (i == 0 || !visited[i - 1])) {
            visited[i] = true;
            operate(cnt, current + 1, visited);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    string input;
    cin >> input;

    // 입력 처리
    for (int i = 0; i < input.length(); i++) {
        if (i % 2 == 1) {
            arr[i] = (char)input[i];
        } else {
            arr[i] = input[i] - '0';
        }
    }

    make_comb();

    int comb = (n / 2) + 1;
    for (int i = 0; i <= comb; i++) {
        vector<bool> visited(v.size(), false);
        operate(i, 0, visited);
    }

    cout << ans << endl;

    return 0;
}
