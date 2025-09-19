#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    // a의 최대 공약수, b의 최대공약수 구하기/ a의 최대 공약수, b의 최대공약수 구하기
   
    int gcdA = arrayA[0];
    for (int i = 1; i < arrayA.size(); i++) {
        gcdA = gcd(gcdA, arrayA[i]);
    }
    
    int gcdB = arrayB[0];
    for (int i = 1; i < arrayB.size(); i++) {
        gcdB = gcd(gcdB, arrayB[i]);
    }
    bool flagA = true;
    for(int i=0;i<arrayA.size();i++){
        if(arrayA[i]%gcdA!=0){
            flagA=false;
            break;
        }
    }
    for(int i=0;i<arrayB.size();i++){
        if(arrayB[i]%gcdA==0){
            flagA=false;
            break;
        }
    }
    
    bool flagB = true;
    for(int i=0;i<arrayA.size();i++){
        if(arrayA[i]%gcdB==0){
            flagB=false;
            break;
        }
    }
    for(int i=0;i<arrayB.size();i++){
        if(arrayB[i]%gcdB!=0){
            flagB=false;
            break;
        }
    }
    if(flagB&&flagA){
        return max(gcdA,gcdB);
    }else if(flagA){
        return gcdA;
    }else if(flagB){
        return gcdB;
    }
    return answer;
}