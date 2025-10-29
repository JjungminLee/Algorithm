#include <bits/stdc++.h>

using namespace std;
int N,M;
int truth;
vector<int> truthV;
int arr[55][55];
int parent[55];



int finds(int a){
    if(parent[a]==a){
        return a;
    }
   return parent[a]= finds(parent[a]);
    

}
void unions(int a,int b){
    a = finds(a);
    b  = finds(b);

    if(a<b){
        parent[b]=a;
    }else{
        parent[a]=b;
    }    
}


int main(){
    cin>>N>>M;
    cin>>truth;
    for(int i=0;i<55;i++){
        parent[i]=i;
    }
    for(int i=0;i<truth;i++){
        int num;
        cin>>num;
        // 진실을 아는 사람은 0으로!
        parent[num]=0;
    }
   
    for(int i=0;i<M;i++){
        int n;
        cin>>n;
        arr[i][0]=n;
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
        
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
               if(arr[i][j]!=arr[i][k]){
                 unions(arr[i][j],arr[i][k]);
               }
            }
        }
           
    }
    
   
    int ans =0;
    for(int i=0;i<M;i++){
        int n = arr[i][0];
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(finds(parent[arr[i][j]])==0){
                flag=false;
             

            }
        }
        if(flag){
            ans++;
        }
    }
    // for(int i=1;i<=N;i++){
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
  
    cout<<ans<<endl;
  
  

}