#include <string>
#include <vector>
#include <iostream>
using namespace std;
int N = 0;
int answer=0;
int targetNum=0;
vector<int> arr;

void dfs(int depth,int num){
    if(depth==N){
        if(num==targetNum){
    
            answer++;
            return;
        }
        
    }else{
        // num에 arr[depth]*(-1) 더하기
        dfs(depth+1,num+arr[depth]*(-1));
        
        // num에 arr[depth]*1 더하기
        dfs(depth+1,num+arr[depth]);

    }
    
}

int solution(vector<int> numbers, int target) {
    targetNum = target;
    N=numbers.size();
    for(int i=0;i<numbers.size();i++){
        arr.push_back(numbers[i]);
    }
    dfs(0,0);
    return answer;
}

int main(){
    cout<<solution({1,1,1,1,1},3)<<endl;
}