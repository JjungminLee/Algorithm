#include<bits/stdc++.h>
using namespace std;

int n;
int m;
int arr[10001];

vector<int> v;
vector<pair<int,int>> recom;

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    
  
    int idx = 0;
    
    
    
    while (1) {
        // cout<<"rec"<<endl;
        // for(int i=0;i<recom.size();i++){
        //     cout<<"first "<<recom[i].first<<"second "<<recom[i].second<<endl;
        // }
        // cout<<endl;
        // cout<<"v "<<endl;
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        if (idx >= m) {
           
            break;
        }
        
     
        
        if (v.size() == n) {
            sort(v.begin(), v.end(), [&](int a, int b) {
                int a_rec = 0;
                int b_rec = 0;
                
                for (int i = 0; i < recom.size(); i++) {
                    if (recom[i].first == a) {
                        a_rec = recom[i].second;
                     
                    }
                    if (recom[i].first == b) {
                        b_rec = recom[i].second;
                   
                    }
                }
                
                if (a_rec == b_rec) {
                    int a_idx = -1, b_idx = -1;
                    for (int i = 0; i <= idx; i++) {
                        if (arr[i] == a && a_idx == -1) a_idx = i;
                        if (arr[i] == b && b_idx == -1) b_idx = i;
                    }
                    return a_idx < b_idx;
                    
                   
                }
                
                return a_rec < b_rec;
            });

            //새롭게 넣는애가 v배열속에 있는 경우 recom에서 1만 증가
            bool isExist=false;
            for(int i=0;i<v.size();i++){
                if(arr[idx]==v[i]){
                    isExist=true;
                    break;
                }
            }

            if(isExist){
                for(int i=0;i<recom.size();i++){
                    if(arr[idx]==recom[i].first){
                        recom[i].second+=1;
                        break;
                    }
                }
            }else{
                  // 새롭게 넣는 애가 v배열 속에 없는 경우 v에서 맨앞에 제거, recom값도 0으로 초기화
                  // 새롭게 넣는애 추가
                for(int i=0;i<recom.size();i++){
                    if(v[0]==recom[i].first){
                        recom[i].second=0;
                        break;
                    }
                }
                v.erase(v.begin());
                v.push_back(arr[idx]);
                recom.push_back({arr[idx],1});
            }

          
            
        }else if(v.size()<n){
            //이미 v에 있는 경우 추천횟수만 증가
            bool isExist=false;
            for(int i=0;i<v.size();i++){
                if(arr[idx]==v[i]){
                    isExist=true;
                    break;
                }
            }
            if(isExist){
                for(int i=0;i<recom.size();i++){
                    if(arr[idx]==recom[i].first){
                        recom[i].second+=1;
                        break;
                    }
                }
            }else{

                //v에 없는 경우 추가
                recom.push_back({arr[idx],1});
                v.push_back(arr[idx]);
            }


        }
        
        
        idx++;
    }
    sort(v.begin(),v.end());
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
  
    cout << endl;

    return 0;
}
