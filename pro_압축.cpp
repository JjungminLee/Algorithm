#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<string> vAns;
    string alpha[6] = {"A", "B", "C", "D", "E", "F"};

    if (n <= 10) {
        for (int i = 0; i < t * 20; i++) {
            vector<string> v;
            while (true) {
                int remainder = int(i % n);
                v.insert(v.begin(), to_string(remainder));
                i = int(i / n);
                if (i == 0) {
                    break;
                }
            }
            for (int j = 0; j < v.size(); j++) {
                vAns.push_back(v[j]);
            }
        }
    } else if (n >= 11) {
        for (int i = 0; i < t * 20; i++) {
            vector<string> v;
            while (true) {
                int remainder = int(i % n);
                if (remainder >= 10) {
                    v.insert(v.begin(), alpha[remainder - 10]);
                } else {
                    v.insert(v.begin(), to_string(remainder));
                }

                i = int(i / n);

                if (i == 0) {
                    break;
                }
            }
            for (int j = 0; j < v.size(); j++) {
                vAns.push_back(v[j]);
            }
        }
    }

    for (int i = p - 1; i < vAns.size(); i += m) {
        if (answer.length() == t * m) {
            return answer;
        } else {
            answer.append(vAns[i]);
        }
    }

    return answer;
}

int main() {
    cout << solution(2, 4, 2, 1) << endl;
    return 0;
}
