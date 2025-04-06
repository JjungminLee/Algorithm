#include <bits/stdc++.h>
using namespace std;
int n;
set<char> st;
int main()
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<string> words;
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        bool assigned = false;
        // 각  단어들 첫글자 부터 판단
        for (int j = 0; j < words.size(); j++)
        {
            char ch = toupper(words[j][0]);
            if (st.count(ch) == 0)
            {
                st.insert(ch);
                assigned = true;
                int pos = str.find(words[j]);
                str.insert(pos, "[");
                str.insert(pos + 2, "]");
                break;
            }
        }
        // 단축키 지정이 안되었다면 왼쪽에서부터 차례대로 알파벳을 보면서 단축키로 지정 안 된 것이 있다면 단축키로 지정
        if (!assigned)
        {
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] == ' ')
                {
                    continue;
                }
                char ch = toupper(str[j]);
                if (st.count(ch) == 0)
                {
                    st.insert(ch);
                    str.insert(j, "[");
                    str.insert(j + 2, "]");
                    break;
                }
            }
        }
        cout << str << endl;
    }
}