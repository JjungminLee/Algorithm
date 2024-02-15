#include <bits/stdc++.h>

using namespace std;

int n;

struct Node{
    int priorityNum;
    int curIdx;
    Node(int _pN,int _cI): priorityNum(_pN),curIdx(_cI){};
};




int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        int cnt=1;
        vector<Node>vecQ;
        vector<Node>printVec;
        int arr[a];


        // a= 문서의 개수 
        // 몇번째로 인쇄됐는지 궁금한 문서가 현재 b에 있다.
        for(int j=0;j<a;j++){
            cin>>arr[j];
                        
        }
        for(int j=0;j<a;j++){
                    int std = arr[j];
                    bool flag=true;
                    for(int k=j+1;k<a;k++){
                        if(std<arr[k]){
                            flag=false;
                        }
                    }
                    
                   
                    if(flag==0){
                        // 더 큰게 있다면 큐의 뒤에
                        vecQ.push_back(Node(std,j));
                        
                    }else if(flag==1){
                        // 더 큰게 없다면 프린터에 넣기
                        printVec.push_back(Node(std,j));
                        
                    }
        }
        while(true){
            if(vecQ.size()==0){
                break;
            }else{
               
                for(int j=0;j<vecQ.size();j++){
                    int std = vecQ[j].priorityNum;
                    int idx=vecQ[j].curIdx;
                    
            
                    bool flag=true;
                    
                    for(int k=j+1;k<vecQ.size();k++){
                        if(std<vecQ[k].priorityNum){
                            flag=false;
                        }
                    }
              
                    if(flag==0){
                        vecQ.push_back(Node(std,idx));
                        vecQ.erase(vecQ.begin()+j);
                    }else{
                         vecQ.erase(vecQ.begin()+j);
                        printVec.push_back(Node(std,idx));
                    }
                }
            }
        }
        for(int j=0;j<printVec.size();j++){
    
            if(printVec[j].curIdx==b){
                break;
            }else{
                cnt++;
            }
        }
        
        cout<<cnt<<endl;
     

    }

}