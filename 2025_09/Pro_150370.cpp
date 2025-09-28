#include <bits/stdc++.h>

using namespace std;

map<string,int>mp;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int todayYear = stoi(today.substr(0,4));
    int todayMonth = stoi(today.substr(5,2));
    int todayDay = stoi(today.substr(8,2));
    
    // 약관 map에
    for(int i=0;i<terms.size();i++){
        string a,b;
        int idx = 0;
        for(int j=0;j<terms[i].size();j++){
            if(terms[i][j]==' '){
                idx=j;
                break;
            }
        }
        for(int j=0;j<idx;j++){
            a+=terms[i][j];
        }
        
        for(int j=idx+1;j<terms[i].size();j++){
            b+=terms[i][j];
        }
        mp[a]=stoi(b);
    }
    
    // privacy
    for(int i=0;i<privacies.size();i++){
        string str = privacies[i];
        
        string a,b;
        int idx = 0;
        for(int j=0;j<privacies[i].size();j++){
            if(privacies[i][j]==' '){
                idx=j;
                break;
            }
        }
        for(int j=0;j<idx;j++){
            a+=privacies[i][j];
        }
        
        for(int j=idx+1;j<privacies[i].size();j++){
            b+=privacies[i][j];
        }
        
        int len = mp[b];
        int year = stoi(a.substr(0,4));
        int month = stoi(a.substr(5,2));
        int day = stoi(a.substr(8,2));
        
        
        int yLen = len/12;
        int mLen = len%12;
        
        year+=yLen;
        month+=mLen;
        
        if(month>12){
            month = month%12;
            year+=1;
            if(day==1){
                day=28;
                month-=1;
                if(month==0){
                    month=12;
                    year-=1;
                }
            }else{
                day-=1;
            }
        }else{
            if(day==1){
                day=28;
                month-=1;
                if(month==0){
                    month=12;
                    year-=1;
                }
            }else{
                day-=1;
            }
            
        }
        //cout<<year<<" "<<month<<" "<<day<<endl;
        if(year<todayYear){
            answer.push_back(i+1);
        }else if(year==todayYear&&month<todayMonth){
            answer.push_back(i+1);
        }else if(year==todayYear&&month==todayMonth&&day<todayDay){
            answer.push_back(i+1);
        }
        
        
        
        
    }
    
    
    return answer;
}