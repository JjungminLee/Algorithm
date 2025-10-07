#include<bits/stdc++.h>

using namespace std;
long long N;
vector<long long>v(6);

long long three;
long long two;
long long one;

int main(){
    cin>>N;
    for(int i=0;i<6;i++){
        long long num;
        cin>>num;
        v[i]=num;
    }

    vector<pair<int,int>>opp={{0,5},{1,4},{2,3}};

    if(N==1){
        sort(v.begin(),v.end());
        int cnt = 0;
        for(int i=0;i<5;i++){
            cnt+=v[i];
        }
        cout<<cnt<<"\n";
        return 0;
    }

    vector<long long>tmpv = v;
    sort(tmpv.begin(),tmpv.end());

    long long one = tmpv[0];
    long long two = LLONG_MAX;

    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            bool opposite = false;
            for(auto &p:opp){
                if((p.first==i&&p.second==j)||
            (p.first==j&&p.second==i)){
                    opposite=true;
                }
            }
            // 마주보면 동시에 보여질수 없음
            if(!opposite){
                two = min(two,v[i]+v[j]);
            }
        }
    }

    long long three = LLONG_MAX;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                bool valid = true;

                for(auto p:opp){
                    // 서로 마주보는 쌍이 포함되면 안됨!
                    int cnt = (p.first==i) + (p.first==j) + (p.first==k)
                    + (p.second==i)+(p.second==j)+(p.second==k);
                    if(cnt>=2) valid=false;
                }

                if(valid){
                    three = min(three,v[i]+v[j]+v[k]);
                }
            }

            

        }
    }

    long long ans = 0;
    ans += 4*three;
    ans +=( 8*(N-2) + 4*(N-1))*two;
    ans += (N-2)*(5*N-6)*one;
    cout<<ans<<"\n";


    

}