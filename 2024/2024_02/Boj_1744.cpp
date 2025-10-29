#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> v;
int outerIdx;
int ans = 0;
int negativeCnt;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
  
    if(N==1){
        cout<<v[0]<<endl;
    }else if(N==2){
        cout<<max(v[0]+v[1],v[0]*v[1])<<endl;

    }else{
        int cnt =0 ;

        int negativIdx=0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=0){
                negativeCnt++;
                negativIdx=i;
            }else{
                break;
            }
        }
    
        //음수가 없을 경우
        int idx=N-1;
        if(negativeCnt==0){
            if(N%2==0){
                // 양수가 짝수개일 때
                while(idx>=1){
                    if(v[idx]!=1&&v[idx-1]!=1){
                        cnt+=v[idx]*v[idx-1];
                    }else{
                        cnt+=v[idx];
                        cnt+=v[idx-1];
                    }
                    idx-=2;
                }

            }else{
                // 양수가 홀수개 일때 
                while(idx>=2){
       
                    if(v[idx]!=1&&v[idx-1]!=1){
      
                        cnt+=(v[idx]*v[idx-1]);
     
                    }else{
                        cnt+=v[idx];
                        cnt+=v[idx-1];
                    }
                    idx-=2;
           
                }
                 
                cnt+=v[0];
               
            }
            
        }
        else{
            if(negativeCnt%2==0){
            //음수가 짝수개인경우
         
            for(int i=0;i<=negativIdx;i+=2){
                cnt+=(v[i]*v[i+1]);
            }
            //양수개수
            int positiveCnt = N-negativeCnt;
            int idx=N-1;
            if(positiveCnt%2==0){
                //양수가 짝수개인 경우
                while(idx>negativIdx+1){
                    if(v[idx]!=1&&v[idx-1]!=1){
                        cnt+=v[idx]*v[idx-1];
                    }else{
                        cnt+=v[idx];
                        cnt+=v[idx-1];
                    }
                    idx-=2;
                }

            }else{
                
                while(idx>negativIdx+2){
                    if(v[idx]!=1&&v[idx-1]!=1){
                        cnt+=v[idx]*v[idx-1];
                    }else{
                        cnt+=v[idx];
                        cnt+=v[idx-1];
                    }
                    idx-=2;
                }
                
                cnt+=v[negativIdx+1];
            }
            
        }else{
                //음수가 홀수개인경우
                for(int i=0;i<=negativIdx-1;i+=2){
                    cnt+=(v[i]*v[i+1]);
                }
                cnt+=v[negativIdx];
           
                //양수개수
                int positiveCnt = N-negativeCnt;
   
                if(positiveCnt%2==0){
                     //양수가 짝수개인 경우
 
                    while(idx>negativIdx+1){
                        if(v[idx]!=1&&v[idx-1]!=1){
                            cnt+=v[idx]*v[idx-1];
                        }else{
                            cnt+=v[idx];
                            cnt+=v[idx-1];
                        }
                        idx-=2;
                    }

                }else{
                    //양수가 홀수개인 경우
                    while(idx>negativIdx+2){
                        if(v[idx]!=1&&v[idx-1]!=1){
                            cnt+=v[idx]*v[idx-1];
                        }else{
                            cnt+=v[idx];
                            cnt+=v[idx-1];
                        }
                        idx-=2;
                    }
     
                    cnt+=v[negativIdx+1];
        
                }

            }
        }

        ans=max(ans,cnt);
        cout<<ans<<endl;
        

    }

    

}