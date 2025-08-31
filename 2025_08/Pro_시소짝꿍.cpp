#include <bits/stdc++.h>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long>cnt(1001,0);

    // 1:1
    for(int i:weights){
        cnt[i]++;
    }
    // 2:3
    // 2:4 -> 1:2
    // 3:4
    for(int i:weights){
        if(i%2==0){
            long long tmp = (i/2)*3;
            if(tmp<=1000){
                answer+=cnt[tmp];  
            }
        }
        if(i%3==0){
            long long tmp = (i/3)*4;
            if(tmp<=1000){
                answer+=cnt[tmp];  
            }
        }
        long long tmp = i*2;
        if(tmp<=1000){
                answer+=cnt[tmp];  
        }
    }
    for(int i=100;i<=1000;i++){
        if(cnt[i]>=2){
            answer += (cnt[i]*(cnt[i]-1))/2;
        }
    }
    return answer;
}