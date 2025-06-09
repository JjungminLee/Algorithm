#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> avector;
vector<int> bvector;
vector<int> cvector;
vector<int> dvector;
vector<int> ab;
vector<int> cd;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        avector.push_back(a);
        bvector.push_back(b);
        cvector.push_back(c);
        dvector.push_back(d);

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ab.push_back(avector[i]+bvector[j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cd.push_back(cvector[i]+dvector[j]);
        }
    }
    sort(ab.begin(),ab.end());
    sort(cd.begin(),cd.end());
    // ab + cd 가 0이 되는

    long long res=0;
    // left는 ab 배열만 사용, right 는 cd배열만 사용
    int left = 0;
    int right = n*n-1;
    while(left<ab.size()&&right>=0){
      int sum = ab[left]+cd[right];
      if(sum==0){
        // 값이 중복된 경우 생각
        long long cntAB=1;
        long long cntCD=1;
        while(left+1<ab.size()&&ab[left]==ab[left+1]){
            cntAB++;
            left++;
        }
        while(right-1>=0&&cd[right]==cd[right-1]){
            cntCD++;
            right--;
        }
        res+=(cntAB*cntCD);
        left++;
        right--;

      }else if(sum<0){
        left++;
      }else{
        right--;
      }
    }
    cout<<res<<endl;

}