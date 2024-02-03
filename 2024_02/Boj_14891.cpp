#include <bits/stdc++.h>

using namespace std;
int arr[4][8];
int k;

// 맞물린 애들이 서로 같은 방향인지 확인한다
// 맞물린 애들이 서로 다른 방향인 경우 회전한다
// 최종 판단

// 맞물린애들이 서로 같은 방향인지 판단
// 맞물리면 -1을 리턴 맞물리지 않으면 체인숫자를 리턴
int firstSecondChain(){
    if(arr[0][2]!=arr[1][6]){
        return 2;
    }
    return -1;
}
int secondFirstChain(){
    if(arr[0][2]!=arr[1][6]){
        return 1; 
    }
    return -1;
}


int secondThirdChain(){
   if(arr[1][2]!=arr[2][6]){
        return 3; 
    }
    return -1;
}
int thirdSecondChain(){
    if(arr[1][2]!=arr[2][6]){
        return 2; 
    }
    return -1;
}
int thirdFourthChain(){
    if(arr[2][2]!=arr[3][6]){
        return 4;
    }
    return -1;
}
int fourthThirdChain(){
    if(arr[2][2]!=arr[3][6]){ 
        return 3;
    }
    return -1;

}
void rotateFunc(int idx,int rotateDir){
    // 시계방향(1)일 경우
    // 맨마지막 인덱스를 맨앞으로 나머지 뒤로 한칸씩
    int arr_copy[8]={};
  
    if(rotateDir==1){
        for(int i=0;i<8;i++){
            arr_copy[i]=arr[idx][i];
        }
        arr[idx][0]=arr_copy[7];
        for(int i=1;i<8;i++){
            arr[idx][i]=arr_copy[i-1];
        }
        

    }else if(rotateDir==-1){
        // 시계반대방향(-1)일 경우
        // 맨 처음 인덱스를 맨뒤로 나머지 앞으로 한칸씩
        for(int i=0;i<8;i++){
            arr_copy[i]=arr[idx][i];
        }
        arr[idx][7]=arr_copy[0];
        for(int i=0;i<7;i++){
            arr[idx][i]=arr_copy[i+1];
        }

    }

    

}

int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            char c;
            cin>>c;
            arr[i][j]=c-'0';
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int num,rotate;
        cin>>num>>rotate;
        if(num==1){
            int idx2 = firstSecondChain(); //2
            int idx3 = secondThirdChain(); //3
            int idx4 = thirdFourthChain(); //4
            rotateFunc(num-1,rotate);
            if(idx2==2){
                rotateFunc(idx2-1,rotate*(-1));
                if(idx3==3){
                    rotateFunc(idx3-1,rotate);
                    if(idx4==4){
                        rotateFunc(idx4-1,rotate*(-1));
                    }
                }
            }
        }
        else if(num==2){
            int idx1 = secondFirstChain(); //1
            int idx3 = secondThirdChain(); //3
            int idx4 = thirdFourthChain(); //4
            rotateFunc(num-1,rotate);
            if(idx1==1){
                 rotateFunc(idx1-1,rotate*(-1));

            }
            if(idx3==3){
                 rotateFunc(idx3-1,rotate*(-1));
                 if(idx4==4){
                    rotateFunc(idx4-1,rotate);

                 }

            }
           

        }else if(num==3){
            int idx1 = secondFirstChain(); //1
            int idx2 = thirdSecondChain(); //2
            int idx4 = thirdFourthChain(); //4
            rotateFunc(num-1,rotate);
            
            if(idx2==2){
               
                rotateFunc(idx2-1,rotate*(-1));
                if(idx1==1){
                 rotateFunc(idx1-1,rotate);
                }

            }
            if(idx4==4){
                
                 rotateFunc(idx4-1,rotate*(-1));
            }
            

        }else if(num==4){
            int idx1 = secondFirstChain(); //1
            int idx2 = thirdSecondChain(); //2
            int idx3 = fourthThirdChain(); //3
            rotateFunc(num-1,rotate);
            if(idx3==3){
                 rotateFunc(idx3-1,rotate*(-1));
                if(idx2==2){
                    rotateFunc(idx2-1,rotate);
                    if(idx1==1){
                        rotateFunc(idx1-1,rotate*(-1));
                    }
                }
            }

        }
        
    }
    int ans = 0;
    if(arr[0][0]==0){
        ans+=0;
    }else{
        ans+=1;
    }
    if(arr[1][0]==0){
        ans+=0;
    }else{
        ans+=2;
    }
    if(arr[2][0]==0){
        ans=ans;
    }else{
        ans+=4;

    }
    if(arr[3][0]==0){
        ans=ans;
    }else{
        ans+=8;
    }
    cout<<ans<<endl;

}