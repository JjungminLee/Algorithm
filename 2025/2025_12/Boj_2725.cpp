#include<bits/stdc++.h>

using namespace std;

int n;
int arr[1005];
int euiler[1005];
int main(){
    int c;
    cin>>c;
    arr[1]=3;

    for(int i=1;i<=1000;i++){
        euiler[i]=i;
    }

    for(int i=2;i<=1000;i++){
        if(euiler[i]==i){
            for(int j=i;j<=1000;j+=i){
                euiler[j]-=euiler[j]/i;
            }
        }
    }
    for(int i=2;i<=1000;i++){
        arr[i]=arr[i-1]+2*euiler[i];
    }
    
    for(int i=0;i<c;i++){
        int num;
        cin>>num;
        cout<<arr[num]<<"\n";
    }


}