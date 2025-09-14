#include<bits/stdc++.h>
using namespace std;

int T;

int makeD(int num){
    return (num*2)%10000;
}

int makeS(int num){
    return num==0?9999:num-1;
}

int makeL(int num){
    int first = num/1000;
    return (num%1000)*10+first;
}

int makeR(int num){
    int last = ((num%1000)%100)%10;
    return (num/10)+last*1000;
}

int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        int a,b;
        cin>>a>>b;
        bool visited[100000]={false,};
        queue<pair<int,string>>q;
        q.push({a,""});
        visited[a]=true;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(cur.first==b){
                for(int i=0;i<cur.second.size();i++){
                    cout<<cur.second[i];
                }
                cout<<"\n";
                break;
            }
            int cal[4]={makeD(cur.first),makeS(cur.first),makeL(cur.first),makeR(cur.first)};
            char alpha[4]={'D','S','L','R'};
            for(int i=0;i<4;i++){
                if(!visited[cal[i]]){
                    visited[cal[i]]=true;
                    string path = cur.second;
                    path+=alpha[i];
                    q.push({cal[i],path});
                }
            }

        }
        
    }

}