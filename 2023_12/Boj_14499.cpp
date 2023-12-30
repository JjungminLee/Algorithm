#include <iostream>
#include <vector>
using namespace std;

int N;
int M;
int arr[21][21];
int x;
int y;
int k;
vector<int> dice(6);

// 0-> 위 1 -> 아래 2 -> 북 3 -> 남 4 ->서 5 -> 동
//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4

bool moveXY(int order){

    int nx = x;
    int ny = y;
    if(order==1){
        ny ++;
    }else if(order==2){
        ny --;
    }else if(order==3){
        nx --;
    }else{
        nx ++;
    }
    if(nx<0||nx>=N||ny<0||ny>=M){
        
        return false;
    }else{
        x = nx;
        y = ny;
         return true;
    }

}

// 0-> 위 1 -> 아래 2 -> 북 3 -> 남 4 ->서 5 -> 동
//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4

void roll(int order){
    vector<int>tmp = dice;

    // 동
    if(order==1){
        dice[0] = tmp[4];
        dice[1] =  tmp[5];
        dice[4] = tmp[1];
        dice[5] = tmp[0];
    }
    //서
    else if(order==2){
        dice[0] = tmp[5];
        dice[1] =  tmp[4];
        dice[4] = tmp[0];
        dice[5] = tmp[1];

    }
    // 북
    else if(order==3){
        dice[0] = tmp[3];
        dice[1] = tmp[2];
        dice[2] = tmp[0];
        dice[3] = tmp[1];

    }
    // 남
    else{
        dice[0]= tmp[2];
        dice[1] = tmp[3];
        dice[2] = tmp[1];
        dice[3] = tmp[0];

    }

}
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>N>>M>>x>>y>>k;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<k;i++){
        int order;
        cin>>order;
        if(!moveXY(order)){
            continue;
        }
        else{
            roll(order);
        }

        // arr이 0이 아니라면 
        if(arr[x][y]!=0){
            dice[1]=arr[x][y];
            arr[x][y]=0;

        }else{
            arr[x][y]=dice[1];
        }

        cout<<dice[0]<<"\n";
    }
    return 0;

}