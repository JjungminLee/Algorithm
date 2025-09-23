#include <bits/stdc++.h>
using namespace std;

map<string,int>mp;
vector<pair<string,int>>v;
map<string,vector<pair<int,int>>>mpV;

bool compares(pair<string,int>a,pair<string,int>b){
    return a.second>b.second;
}

bool comparesInt(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first){
        a.second<b.second;
    }
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        string str = genres[i];
        mp[str]+=plays[i];
        mpV[str].push_back({plays[i],i});
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        v.push_back({it->first,it->second});
    }
    
    sort(v.begin(),v.end(),compares);
    
    for(int i=0;i<v.size();i++){
        string str = v[i].first;
        vector<pair<int,int>>tmp = mpV[str];
        sort(tmp.begin(),tmp.end(),comparesInt);
        int size = tmp.size()>=2?2:tmp.size();
        for(int j=0;j<size;j++){
            answer.push_back(tmp[j].second);
        }
    }
    return answer;
}