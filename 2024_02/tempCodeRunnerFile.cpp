#include <bits/stdc++.h>

using namespace std;
int N,M;
int truth;
vector<int> truthV;
int arr[51][51];
int parent[51];



int finds(int a){
    if(parent[a]==a){
        return a;
    }
    int num = finds(parent[a]);
    return num;

}
void unions(int a,int b){

        int aP=finds(a);
        int bP=finds(b);

        bool aFlag=false;
        for(int i=0;i<truthV.size();i++){
            if(truthV[i]==a){
                aFlag=true;
            }
        }
        bool bFlag=false;
        for(int i=0;i<truthV.size();i++){
            if(truthV[i]==b){
                bFlag=true;
            }
        }
 
        if(aFlag&&!bFlag){
            parent[b]=aP;
        }
        else if(!aFlag&&bFlag){
            parent[a]=bP;
        }
        else if(!aFlag&&!bFlag){
            if(aP<bP){
                parent[bP]=aP;
            }else{
                parent[aP]=bP;
            }
        }
       
}
int main(){
    cin>>N>>M;
    cin>>truth;
    for(int i=0;i<truth;i++){
        int num;
        cin>>num;
        truthV.push_back(num);
    }
    for(int i=0;i<51;i++){
        parent[i]=i;
    }
    for(int i=0;i<M;i++){
        int n;
        cin>>n;
        arr[i][0]=n;
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
        for(int j=1;j<n;j++){
            for(int k=j+1;k<=n;k++){
                unions(arr[i][j],arr[i][k]);
            }
        }
        

    }
    int ans=0;
    for(int i=0;i<M;i++){
        int num = arr[i][0];
        bool flag=false;
        for(int j=1;j<=num;j++){
            int target = parent[arr[i][j]];
            
            for(int k=0;k<truthV.size();k++){
                if(truthV[k]==target){
                    flag=true;
                }
            }
            
        }
        if(!flag){
                ans++;
        }

    }
  
    cout<<ans<<endl;

}