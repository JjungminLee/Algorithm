#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>v;
long long ans;
int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());

    // 0부터 n-2 만큼 돌면서 left의 시작점을 i+1로
    for(int i=0;i<n-2;i++){
        int left=i+1;
        int right = n-1;
        // 세개 뽑아서 합이 0
        while(left<right){
            int sum = v[i]+v[left]+v[right];
            if(sum==0){
                // left와 right 값이 같은 경우
                if(v[left]==v[right]){
                    int cnt = right-left+1;
                    ans+=(cnt*(cnt-1))/2;
                    break;
                }
                // left와 right값이 다른데 그 사이에 중복이 있는 경우
                int cntL=1;
                int cntR=1;
                while(left+1<right&&v[left]==v[left+1]){
                    cntL++;
                    left++;
                }
                while(left<right-1&&v[right]==v[right-1]){
                    cntR++;
                    right--;
                }
                ans+=(cntL*cntR);
                // 중복 넘어가기 안하면 무한루프
                left++;
                right--;
            }else if(sum<0){
                left++;
            }else{
                right--;
            }

        }
    }
    cout<<ans<<endl;
    

}