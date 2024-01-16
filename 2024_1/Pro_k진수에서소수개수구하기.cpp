#include <string>
#include <vector>
#include<iostream>


using namespace std;
vector<int> v;

bool isPrime(int x){
    for(int i=2;i<=x;i++){
        if(x%i==0){
            return false;
        }
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
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    if(v.size()==1&&v[0]!=0){
        answer+=1;
    }else{
        // int idx = 0;
        // while(idx<v.size()){
        //     string str = "";
        //     while(v[idx]!=0){
        //         str+=to_string(v[idx]);
        //         idx+=1;
        //         cout<<idx<<endl;

        //     }
        //     cout<<str<<endl;
        // }
   

    }
    return answer;
}
int main(){
    cout<<solution(437674,3)<<endl;
}