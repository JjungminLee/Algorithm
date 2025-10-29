#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int>pq;
    // 무적권은 우선순위큐로 내림차순 정렬
    for(int i=0;i<enemy.size();i++){
        n-=enemy[i];
        pq.push(enemy[i]);
       
        if(n<0){
            if(k>0){
                n+=pq.top();
                pq.pop();
                k--;
                
            }else{
                break;
            }
        }
        answer++;
        
    }
    return answer;
}