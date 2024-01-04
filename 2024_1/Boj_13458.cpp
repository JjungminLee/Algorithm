#include <iostream>
#include <vector>
using namespace std;

int N;
int B;
int C;
long cnt;
vector<int> v;
int main(){
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++){
        int n;
        cin>>n;
        v.push_back(n);
    }
    cin>>B>>C;
    for(int i=0;i<N;i++){
        int num = v[i];

        // 총감독관
        num-=B;
        cnt+=1;
        // 부 감독관
        if(num>0){
            if(num/C==0){
                cnt+=1;
            }else if(num%C==0){
                 cnt+=(num/C);
            }else if(num/C>=1 && num%C!=0){
                cnt+=(num/C)+1;
            }
            
        }
    }
    cout<<cnt<<endl;


}