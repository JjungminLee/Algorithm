#include <bits/stdc++.h>
using namespace std;

int n;
set<char> used;
// 단어 저장할 필요가 없었음 그냥 문자만 set에 있는지 판단하면 됐음
int main()
{
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        string line;
        // 공백 포함 입력받기
        getline(cin, line);
        vector<string> words;
        stringstream ss(line);
        string word;
        // 공백 단위로 자르기
        while (ss >> word)
        {
            words.push_back(word);
        }

        bool isAssigned = false;
        for (int j = 0; j < words.size(); j++)
        {
            char ch = toupper(words[j][0]);
            if (used.count(ch) == 0)
            {
                used.insert(ch);
                int p = line.find(words[j]);
                line.insert(p, "[");
                line.insert(p + 2, "]");
                isAssigned = true;
                break;
            }
        }
        if (!isAssigned)
        {
            for (int j = 0; j < line.size(); j++)
            {
                if (line[j] == ' ')
                {
                    continue;
                }
                char ch = toupper(line[j]);
                if (used.count(ch) == 0)
                {
                    used.insert(ch);
                    line.insert(j, "[");
                    line.insert(j + 2, "]");
                    break;
                }
            }
        }
        cout << line << endl;
    }
}
