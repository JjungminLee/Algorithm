#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;
int d,k;
int main(){
    cin>>d>>k;
    v.push_back({1,0});
    v.push_back({0,1});
    for(int i=2;i<d;i++){
        int x1,y1,x2,y2;
        x1=v[i-2].first;
        y1=v[i-2].second;
        x2=v[i-1].first;
        y2=v[i-1].second;
        v.push_back({x1+x2,y1+y2});
    }
    int x=v[d-1].first;
    int y=v[d-1].second;
    int a=0;
    int b=0;
    for(int i=1;i<=100000;i++){
        a=i*x;
        if((k-a)%y==0){
            b = (k-a)/y;
            a=i;
            break;

        }
        

    }
    cout<<a<<endl;
    cout<<b<<endl;
}