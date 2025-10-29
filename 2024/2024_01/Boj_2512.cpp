#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
int ansCnt;
int maxNum;
int ans;
int main(){
    
    cin>>N;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    cin>>maxNum;
    sort(v.begin(),v.end());
    int start = 1; // 이진탐색 예외처리를 위해 v[0] 이 아닌 1로 둘것!
    int end = v[N-1];

    while(start<=end){
        int mid = (start+end)/2;
        int cnt = 0;
        for(int i=0;i<N;i++){
            if(v[i]>mid){
                cnt+=mid;
            }else{
                cnt+=v[i];
            }
        }
        if(maxNum>=cnt){
            ans=mid;
            ansCnt = max(ansCnt,cnt);
        }
    
        if(cnt>maxNum){
            end=mid-1;
        }else{
            start=mid+1;
        }
        
    }
    cout<<ans<<endl;
    

}