#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> v;
int T;

int main(){

    ios::sync_with_stdio(0);
    cin>>T;
    int targetNum=1;
    int step =0;
    while(true){
        if(targetNum>=10000){
            break;
        }else{
            targetNum+=step;
            v.push_back(targetNum);
            step++;

        }
    }
    for(int i=0;i<T;i++){
        int s,e;
        cin>>s>>e;
        if(s==e){
            cout<<"#"<<i+1<<" "<<0<<endl;
         
        }else{
            int startIdx=0;
            int endIdx=0;
            for(int j=0;j<v.size();j++){
                if(s<=v[j]){
                   if(s==v[j]){
                     startIdx=j+1;
                   
                   }else{
                    startIdx=j;
                   }
                   break;

                }
            }
            for(int j=0;j<v.size();j++){
                if(e<=v[j]){
                    if(e==v[j]){
                        endIdx=j+1;
                   
                   }else{
                        endIdx=j;
                   }
                   break;

                }
            }
    
            if(abs(startIdx-endIdx)==0){
                // 같은 레벨에서 이동
                cout<<"#"<<i+1<<" "<<abs(s-e)<<endl;
            }else{
                //다른 레벨에서 이동
                // 레벨 이동 경계값 계산
                int minIdx = min(startIdx,endIdx);
                int maxIdx = max(startIdx,endIdx);
                int startNum = min(s,e);
                int endNum = max(s,e);
                // cout<<"minIdx"<<minIdx<<endl;
                // cout<<"maxIdx"<<maxIdx<<endl;
                // cout<<startNum<<endNum<<endl;
                // cout<<v[maxIdx]<<endl;
               
                // 왼쪽 끝에서 오른쪽 끝으로 가는 경우
                if(startNum==v[minIdx-1]&&endNum==v[maxIdx]-1){
                   if(maxIdx-minIdx==1){
                     cout<<"#"<<i+1<<" "<<v[maxIdx-1]-v[minIdx-1]<<endl;
                   }else{
                     cout<<"#"<<i+1<<" "<<maxIdx-minIdx+1<<endl;
                   }

                }else if(startNum==v[minIdx-1] && endNum==v[maxIdx-1]){
                       // 왼쪽 끝에서 왼쪽 끝으로 가는 경우
                    cout<<"#"<<i+1<<" "<<maxIdx-minIdx<<endl;
                }else if(startNum==v[minIdx]-1 && endNum==v[maxIdx]-1){
                     // 오른쪽 끝에서 오른쪽 끝으로 가는 경우
                    cout<<"#"<<i+1<<" "<<maxIdx-minIdx<<endl;
                }else if(startNum==v[minIdx]-1&& endNum==v[maxIdx-1]){
                        // 오른쪽 끝에서 왼쪽 끝으로 가는 경우
                    if(maxIdx-minIdx==1){
                     cout<<"#"<<i+1<<" "<<v[maxIdx-1]-v[minIdx-1]<<endl;
                   }else{
                     cout<<"#"<<i+1<<" "<<maxIdx-minIdx+1<<endl;
                   }

                }else if(startNum == v[minIdx]-1 || endNum == v[maxIdx]-1){
                    // 오른쪽 끝으로 가는 경우
                    cout<<"#"<<i+1<<" "<<maxIdx-minIdx+1<<endl;

                }else if(startNum == v[minIdx-1] || endNum == v[maxIdx-1]){
                    // 왼쪽 끝으로 가는 경우
                    cout<<"#"<<i+1<<" "<<maxIdx-minIdx+1<<endl;

                }
                else{
                    cout<<"#"<<i+1<<" "<<maxIdx-minIdx<<endl;

                }

            
        
            }
    

        }

    }

  

    return 0;
}