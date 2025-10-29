#include<bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,int>>v;

bool compares(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int sa,sb,ea,eb;
        cin>>sa>>sb>>ea>>eb;
        v.push_back({sa*100+sb,ea*100+eb});
    }
    
    sort(v.begin(),v.end(),compares);

    int target = 301;
    int endNum = 301;
    int answer = 0;
    int i=0;
    while(target<=1130){
        bool found = false;
        int maxEnd = endNum;
        while(i<N&&v[i].first<=target){
            // 가장 끝이 긴
            if(v[i].second>maxEnd){
                maxEnd = v[i].second;
                found = true;
            }
            i++;
        }

        if(!found){
            cout<<0<<"\n";
            return 0;
        }
        answer ++;
        target = maxEnd;
        endNum = maxEnd;
    }
    
    cout<<answer<<"\n";
    

}