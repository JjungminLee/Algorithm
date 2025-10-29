#include <bits/stdc++.h>

using namespace std;
int N,M;
vector<int> v;

void boy(int idx){
    int gapIdx=idx;
    while(true){
        if(idx>N){
            break;
        }
        if(v[idx]==0){
            v[idx]=1;
        }else{
            v[idx]=0;
        }
        idx+=gapIdx;
    }
}

void girl(int idx){
  
    int leftIdx,rightIdx;
    leftIdx=idx-1;
    rightIdx=idx+1;
   
    while(true){
    
        if(leftIdx<=0||rightIdx>N){
            leftIdx+=1;
            rightIdx-=1;
            break;
        }
      
        if(v[leftIdx]==v[rightIdx]){
            leftIdx-=1;
            rightIdx+=1;
        }else{
            leftIdx+=1;
            rightIdx-=1;
            break;
        }
    }
    for(int i=leftIdx;i<=rightIdx;i++){
      if(v[i]==0){
        v[i]=1;
      }else{
        v[i]=0;
      }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin>>N;
    v.push_back(0);
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }

    cin>>M;
    for(int i=0;i<M;i++){
        int gender,idx;
        cin>>gender>>idx;

        if(gender==1){
            boy(idx);
        }else if(gender==2){
            girl(idx);
        }
    }
    

    for(int i=1;i<=N;i++){
        cout<<v[i]<<" ";
        if(i%20==0){
            cout<<endl;
        }
    }
}