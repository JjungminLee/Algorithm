#include<bits/stdc++.h>

using namespace std;

int n,m,r;
int arr[305][305];

void rotate(){

    int tmp[305][305]={0,};
    int layer = min(n,m)/2;
    for(int i=0;i<layer;i++){

        int top=i;
        int left=i;
        int bottom = n-i-1;
        int right = m-i-1;
        
        // 아래방향으로
        for(int j=top;j<bottom;j++){
            tmp[j+1][left]=arr[j][i];
        }

        // ->
        for(int j=left;j<right;j++){
            tmp[bottom][j+1]=arr[bottom][j];
        }

        // 위 방향으로
        for(int j=bottom;j>top;j--){
            tmp[j-1][right]=arr[j][right];
        }

        //<-
         for(int j=right;j>left;j--){
            tmp[top][j-1]=arr[top][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=tmp[i][j];
        }
    }
}

int main(){
    cin>>n>>m>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<r;i++){
        rotate();
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}