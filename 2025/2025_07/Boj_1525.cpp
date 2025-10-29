#include<bits/stdc++.h>
using namespace std;
string start="";
string target="123456780";
unordered_map<string,int> visited;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int cnt;
int bfs(){
    queue<string>q;
    q.push(start);
    visited[start]=0;
    
    while(!q.empty()){
        string curstr = q.front();
        if(curstr==target){
            return visited[curstr];
        }
        int curx=0;
        int cury=0;
        for(int i=0;i<curstr.size();i++){
            if(curstr[i]=='0'){
                curx=i/3;
                cury=i%3;
            }
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx = curx+dx[i];
            int ny= cury+dy[i];
             if(nx>=0&&nx<3&&ny>=0&&ny<3){
                int idx=3*nx+ny;
                string nextstr=curstr;
                // 0이랑 0에서 상하좌우 이동 가능한 값이랑 자리 바꿈
                swap(nextstr[3*curx+cury],nextstr[idx]);
                if(visited[nextstr]==0){
                    visited[nextstr]=visited[curstr]+1; // 그냥 ++이 아닌 이전 문자열에서 누적
                    q.push(nextstr);
                }
            }
            
           

        }
    }
    return -1;


}
int main(){
    string st;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>st;
            start+=st;
        }
    }
   cout<<bfs()<<endl;
}