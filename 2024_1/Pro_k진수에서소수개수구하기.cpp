#include <string>
#include <vector>
#include<iostream>
#include <cmath>

using namespace std;
vector<long long> v;

bool isPrime(long long n) {
    if(n < 2) return false;
        
    for(int i=2; i<=sqrt(n); ++i) {
        if(n % i == 0) return false;
    }
    
    return true;
}

// 0을 찾아서 0 앞에 있는 애들 잘라버리기

int solution(int n, int k) {
    int answer = 0;
    while(n>k){
        int quotient = n/k;
        int remainder = n%k;
        v.insert(v.begin(),remainder);
        n = quotient;
    }
    v.insert(v.begin(),n%k);

 
    if(v.size()==1&&v[0]!=0){
        answer+=1;
    }else{
        int startIdx = 0;
        int endIdx = 0;
        string str = "";
        while(endIdx<v.size()+1){
            if(v[endIdx]!=0){
                //cout<<endIdx<<endl;
                str+=to_string(v[endIdx]);
                endIdx+=1;
               
            }else{
                if(str!=""){
                    //cout<<str<<endl;
                    if(isPrime(stol(str))){
                        answer+=1;
                    }

                }
                str="";
                startIdx=endIdx;
                endIdx=startIdx+1;
            
            }
        }

    }

    return answer;
}