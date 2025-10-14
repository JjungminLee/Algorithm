#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> mp1;
    map<int,int> mp2;
    for(int num:topping){
        mp1[num]++;
    }
    for(int num:topping){
        mp2[num]++;
        mp1[num]--;
        if(mp1[num]==0){
            mp1.erase(num);
        }
        if(mp2.size()==mp1.size()){
            answer++;
        }
    }
    return answer;
}