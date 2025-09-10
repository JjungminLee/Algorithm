#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> stk;
    int idx = 0;
    for(int box=1;box<=order.size();box++){
        if(order[idx]==box){
            idx++;
            answer++;
            while(!stk.empty()){
                int cur = stk.top();
                if(order[idx]==cur){
                    stk.pop();
                    idx++;
                    answer++;
                }else{
                    break;
                }
            }
        }else{
            stk.push(box);
        }
        
    }
    while(!stk.empty()){
        int cur = stk.top();
    
        if(order[idx]==cur){
            stk.pop();
            idx++;
            answer++;
        }else{
            break;
        }
    }
    return answer;
}