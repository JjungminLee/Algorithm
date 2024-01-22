#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int d[10001];
int T;
void init(){
    int cnt = 0;
    for(int i=1;i<12;i+=cnt){
       for(int j=i;j<=i+cnt;j++){
        
         d[j]=cnt+1;
       }
        cnt++;
    }
    d[1]=1;
}

int main(){

    cin>>T;
    for(int i=0;i<T;i++){
        int s,e;
        cin>>s>>e;
        if(s>e){
            swap(s,e);
        }
        init();
        int sR=s;
        int sL=s;
        int cntR=0;
        int cntL=0;
        while(true){
              
            //같은 레벨일때
            if(d[sR]==d[e]|| d[sL]==d[e]){
                cntR+=abs(e-sR);
                cntL+=abs(e-sL);
                break;
            }
            else{
                sL+=d[s];
                sR+=d[s]+1;
                cntR++;
                cntL++;
                
            }

        }
        cout<<min(cntR,cntL)<<endl;

    }

}