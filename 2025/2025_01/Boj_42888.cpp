#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    // enter,uid
    vector<pair<string, string>> v;
    // uid,name
    unordered_map<string, string> umap;

    for (string &str : record)
    {
        // enter, leave, change인지 판단
        // 문자열을 스트림화
        stringstream ss(str);

        // 스트림을 통해, 문자열을 공백 분리해 변수에 할당
        string first, second, third;
        ss >> first >> second >> third;
        if (first == "Enter")
        {
            v.push_back({"Enter", second});
            umap[second] = third;
        }
        else if (first == "Leave")
        {
            v.push_back({"Leave", second});
        }
        else if (first == "Change")
        {
            umap[second] = third;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        string a = v[i].first;
        string b = umap[v[i].second];
        if (a == "Enter")
        {
            string str = b.append("님이 들어왔습니다.");
            answer.push_back(b);
        }
        else if (a == "Leave")
        {
            string str = b.append("님이 나갔습니다.");
            answer.push_back(b);
        }
    }
    return answer;
}