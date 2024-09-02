#include<bits/stdc++.h>
using namespace std;
int t;
int dir[3]={-1,0,1};
// 최대한 많이 갈 수 있는 만큼 가보고, 안되는 곳은 나머지 숫자로 보충
/*

0->3 (사이거리3)
0(0)->1(1)->2(2) 0에서 1까지 1만큼, 1에서 2까지 1만큼 (1,1,1(마지막1))
이동한거 3 : 사이거리 루트하면 1 -> 반올림한게 더 커짐  2*2-1=3 (3==3)
1-> 5(사이거리 4)
1(0) -> 2(1)-> 4(2) 1에서 2까지 1만큼 2에서 4까지 2만큼 (1,2,1)
이동한거 4 : 사이거리 루트하면 2 -> 반올림 하면 그대로 2*2-1=3
45->50 (사이거리 5)
45(0) -> 46(1)->48(2) -> 49(1) 45에서 46까지 1만큼 46에서 48까지 2만큼 48에서 49까지 1만큼 (1,2,1,1)
이동한거 4 : 사이거리 루트하면 2 -> 반올림 하면 그대로  2*2=4
*/

void move(long long x,long long y){
    double dist=y-x;
    // 소수를 구해야아므로
    double sqrt_dist=sqrt(dist);
    long long round_num = round(sqrt_dist);
    if(sqrt_dist<=round_num){
        cout<<(2*round_num)-1<<endl;
    }else{
        cout<<2*round_num<<endl;
    }
    
}
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        long long x;
        long long y;
        cin>>x>>y;
        move(x,y);
    }
}